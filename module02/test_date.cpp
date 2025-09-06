// test and demonstrate functionality of the Date class

#include "Date.h"   // include custom Date class
#include <iostream> // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

int main() {
    // test with valid month
    cout << "date 1 (2025-09-05): \n";
    // create date 1 object
    Date date_1(2025, 9, 5);
    // display date 1 object
    date_1.display_date();
    cout << "\n";

    // test with invalid month
    cout << "date 2 (2025-31-31): \n";
    // attempt to create date with invalid month
    Date date_2(2025, 31, 31);

    // display date 2 object with default month value of 1
    date_2.display_date();

    cout << "\n";

    // demonstrate using setters

    // use setters to change the date
    cout << "setting date 2 to 2025-12-25\n";
    date_2.set_month(12);
    date_2.set_day(25);
    date_2.set_year(2025);

    // display date 3 with new value
    cout << "date 2 : ";
    date_2.display_date();

    // demonstrate using getters
    cout << "\n";
    cout << "date 2 year: " << date_2.get_year() << endl;
    cout << "date 2 month: " << date_2.get_month() << endl;
    cout << "date 2 day: " << date_2.get_day() << endl;

    return 0;
}
