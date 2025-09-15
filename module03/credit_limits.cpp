// calculates credit balances and indicates when credit limit is exceeded

// provide access to input/output streams and stream manipulators
#include <iomanip>
#include <iostream>

int main() {

    // declare and initialize variables for account info
    int account_number{-1};
    double beginning_balance{0};
    double total_charges{0};
    double total_credits{0};
    double credit_limit{0};
    double new_balance{0};

    // constant for input loop sentinel
    constexpr int SENTINEL = -1;

    // prompt for first account
    std::cout << "Enter account number (or -1 to quit): ";
    std::cin >> account_number;

    // loop until sentinel is entered
    while (account_number != SENTINEL) {
        // prompt for account data
        std::cout << "Enter beginning balance: ";
        std::cin >> beginning_balance;

        std::cout << "Enter total charges: ";
        std::cin >> total_charges;

        std::cout << "Enter total credits: ";
        std::cin >> total_credits;

        std::cout << "Enter credit limit: ";
        std::cin >> credit_limit;

        // calculate new balance
        new_balance = beginning_balance + total_charges - total_credits;

        // display new balance
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "New balance is " << new_balance << "\n";

        // if credit limit is exceeded print account info
        if (new_balance > credit_limit) {
            std::cout << "Account:      " << account_number << "\n";
            std::cout << "Credit limit: " << credit_limit << "\n";
            std::cout << "Balance:      " << new_balance << "\n";
            std::cout << "Credit Limit Exceeded.\n";
        }

        // prompt for next account
        std::cout << "\nEnter account number (or -1 to quit): ";
        std::cin >> account_number;
    }
}
