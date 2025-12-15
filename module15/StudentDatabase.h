#pragma once

#include <sqlite3.h> // access to sqlite3 for bacekend database
#include <string>    // access to string class

class StudentDatabase {
  private:
    sqlite3 *db;

    int get_current_year();
    bool is_valid_graduation_year(int year);
    bool student_exists(int id);

    // for use with sqlite3 to indicate sql is null terminated
    static constexpr int sql_null_termination_indicator = -1;

  public:
    StudentDatabase();
    ~StudentDatabase();

    void display_students();
    void delete_student();
    void update_graduation_year();
    void insert_student();
};
