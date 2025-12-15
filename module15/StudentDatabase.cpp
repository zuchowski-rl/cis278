#include "StudentDatabase.h"
#include <ctime>    // to get current year
#include <iomanip>  // for stream manipulation
#include <iostream> // access to input/output streams

// constructor opens the database
StudentDatabase::StudentDatabase() {
    sqlite3_open("student.db", &db);
}

// destructor closes the database
StudentDatabase::~StudentDatabase() {
    sqlite3_close(db);
}

// returns current year
int StudentDatabase::get_current_year() {
    constexpr int starting_year{1900};
    std::time_t current_time_seconds = std::time(nullptr);
    std::tm *tm_ptr = std::localtime(&current_time_seconds);
    return starting_year + tm_ptr->tm_year;
}

// validates graduation year range
bool StudentDatabase::is_valid_graduation_year(int year) {
    int current_year = get_current_year();
    return year >= current_year && year <= current_year + 4;
}

// checks if student id exists
bool StudentDatabase::student_exists(int id) {
    sqlite3_stmt *stmt;
    const char *sql = "select count(*) from students where id = ?;";
    sqlite3_prepare_v2(db, sql, sql_null_termination_indicator, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    int count{0};
    if (sqlite3_step(stmt) == SQLITE_ROW)
        count = sqlite3_column_int(stmt, 0);

    sqlite3_finalize(stmt);
    return count > 0;
}

// displays all students
void StudentDatabase::display_students() {

    // column indices
    constexpr int index_id = 0;
    constexpr int index_first_name = 1;
    constexpr int index_last_name = 2;
    constexpr int index_major = 3;
    constexpr int index_year = 4;

    // column width settings
    constexpr int id_width{10};
    constexpr int first_name_width{15};
    constexpr int last_name_width{15};
    constexpr int major_width{40};
    constexpr int year_width{5};

    // prepare a sql statement
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM students;";
    sqlite3_prepare_v2(db, sql, sql_null_termination_indicator, &stmt, nullptr);

    // print header
    std::cout << std::left << std::setw(id_width) << "ID" << std::setw(first_name_width)
              << "First Name" << std::setw(last_name_width) << "Last Name" << std::setw(major_width)
              << "Major" << std::setw(year_width) << "Year" << std::endl;

    // print separator
    std::cout << std::string(
                     id_width + first_name_width + last_name_width + major_width + year_width, '-')
              << std::endl;

    // print student records
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << std::left << std::setw(id_width) << sqlite3_column_int(stmt, index_id)
                  << std::setw(first_name_width)
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, index_first_name))
                  << std::setw(last_name_width)
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, index_last_name))
                  << std::setw(major_width)
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, index_major))
                  << std::setw(year_width) << sqlite3_column_int(stmt, index_year) << std::endl;
    }

    // clean up statement
    sqlite3_finalize(stmt);
}

// deletes student by id
void StudentDatabase::delete_student() {

    // id to be deleted
    int id{0};

    // parameter index
    constexpr int index_id = 1;

    // prompt for id
    std::cout << "Enter student id to delete: ";
    std::cin >> id;

    // validate id exists
    if (!student_exists(id)) {
        std::cout << "Student id not found\n";
        return;
    }

    // prepare sql statement
    sqlite3_stmt *stmt;
    const char *sql = "Delete from students where id = ?;";
    sqlite3_prepare_v2(db, sql, sql_null_termination_indicator, &stmt, nullptr);

    // bind id parameter
    sqlite3_bind_int(stmt, index_id, id);

    // execute statement
    sqlite3_step(stmt);
    // clean up statement
    sqlite3_finalize(stmt);

    std::cout << "Student deleted successfully\n";
}

// updates graduation year
void StudentDatabase::update_graduation_year() {
    int id;
    std::cout << "Enter student id: ";
    std::cin >> id;

    if (!student_exists(id)) {
        std::cout << "Student id does not exist\n";
        return;
    }

    int year{0}; // 0 is an invalid year

    // parameterindices
    constexpr int index_year = 1;
    constexpr int index_id = 2;

    // reprompt until valid year is input
    while (!is_valid_graduation_year(year)) {
        std::cout << "Enter new graduation year: ";
        std::cin >> year;

        if (!is_valid_graduation_year(year))
            std::cout << "Invalid graduation year\n";
    }

    // prepare sql statement
    sqlite3_stmt *stmt;
    const char *sql = "Update students set graduation_year = ? where id = ?;";
    sqlite3_prepare_v2(db, sql, sql_null_termination_indicator, &stmt, nullptr);

    // bind parameters
    sqlite3_bind_int(stmt, index_year, year);
    sqlite3_bind_int(stmt, index_id, id);
    // execute statement
    sqlite3_step(stmt);
    // clean up statement
    sqlite3_finalize(stmt);

    std::cout << "Graduation year updated successfully\n";
}

// inserts a new student
void StudentDatabase::insert_student() {
    // column names
    std::string first_name, last_name, major;
    int year{0}; // year 0 is invalid

    // prompt for input
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cin.ignore();

    std::cout << "Enter major: ";
    std::getline(std::cin, major);

    // validate and reprompt for year
    while (!is_valid_graduation_year(year)) {
        std::cout << "Enter graduation year: ";
        std::cin >> year;

        if (!is_valid_graduation_year(year))
            std::cout << "Invalid graduation year\n";
    }

    // parameter indices
    constexpr int index_first_name = 1;
    constexpr int index_last_name = 2;
    constexpr int index_major = 3;
    constexpr int index_year = 4;

    // prepare sql statement
    sqlite3_stmt *stmt;
    const char *sql = "insert into students (first_name, last_name, major, graduation_year) "
                      "values (?, ?, ?, ?);";

    sqlite3_prepare_v2(db, sql, sql_null_termination_indicator, &stmt, nullptr);

    // bind parameters
    sqlite3_bind_text(stmt, index_first_name, first_name.c_str(), sql_null_termination_indicator,
                      SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, index_last_name, last_name.c_str(), sql_null_termination_indicator,
                      SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, index_major, major.c_str(), sql_null_termination_indicator,
                      SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, index_year, year);

    // execute statement
    sqlite3_step(stmt);
    // clean up statement
    sqlite3_finalize(stmt);

    std::cout << "Student added successfully\n";
}
