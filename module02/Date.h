// defining a Date class with setters and getters for year, month, and day
// and a display_date function that prints the date in month/day/year format

#include <iostream> // provide access to input/output streams

class Date {

  private:
    int year{1970}; // data member containing the year value
    int month{1};   // data member containing the month value
    int day{1};     // data member containing the day value

  public:
    // constructor
    Date(int year, int month, int day) : year{year}, day{day} {
        // use set_month to handle invalid month values
        set_month(month);
    }

    // setters
    void set_month(int month) {
        // validate month is between 1 and 12
        if (month >= 1 && month <= 12) {
            this->month = month;
        } else {
            // set invalid months to 1
            std::cout << "Invalid month entered, defaulting to 1." << std::endl;
            this->month = 1;
        }
    }

    void set_year(int year) {
        this->year = year;
    }

    void set_day(int day) {
        this->day = day;
    }

    // getters
    int get_month() const {
        return month;
    }

    int get_year() const {
        return year;
    }

    int get_day() const {
        return day;
    }

    // prints date in month/day/year format
    void display_date() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
};
