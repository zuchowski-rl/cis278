// calculates and displays salaries including commission based on gross sales

// provide access to input/output streams and stream manipulators
#include <iomanip>
#include <iostream>

// function to prompt for and validate sales
double prompt_for_sales(int sentinel) {
    double sales{0.0};

    // prompt for sales input
    std::cout << "\nEnter sales in dollars (" << sentinel << " to end): ";
    std::cin >> sales;

    // test for invalid negative numbers
    while (sales < sentinel) {
        std::cout << "Invalid input. Enter a number >= " << sentinel << ": ";
        std::cin >> sales;
    }

    return sales;
}

int main() {

    // declare and initialize constants for salary calculation
    constexpr double BASE_PAY = 200.0;
    constexpr double COMMISSION_RATE = 0.09;

    // constant for input loop sentinel
    constexpr int SENTINEL = -1;

    // get the first input
    double gross_sales = prompt_for_sales(SENTINEL);

    // process input until sentinel is entered
    while (gross_sales != SENTINEL) {
        // calculate salary
        double salary = BASE_PAY + COMMISSION_RATE * gross_sales;

        // set up cout to display 2 decimal places
        std::cout << std::fixed << std::setprecision(2);
        // display salary
        std::cout << "Salary is: $" << salary << std::endl;

        // get the next input
        gross_sales = prompt_for_sales(SENTINEL);
    }
}
