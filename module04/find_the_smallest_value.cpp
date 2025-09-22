// Write an application that finds the smallest of several integers. Assume that
// the first value read specifies the number of values of input from the user.

#include <iostream> // allow access to input/output streams

int main() {

    // count of values to process
    int value_count{0};

    // holds values to process, initialized on user input of first value
    int current_value;
    int smallest_value;

    // prompt for and validate the count of values to process
    while (value_count < 1) {
        std::cout << "Enter the count of values to process: ";
        std::cin >> value_count;

        if (value_count < 1) {
            std::cout << "Enter a number greater than 0." << std::endl;
        }
    }

    // read the first value and initialize smallest_value
    std::cout << "Enter value 1: ";
    std::cin >> current_value;
    smallest_value = current_value;

    // prompt for and update current_value until value_count is reached
    for (int i = 1; i < value_count; ++i) {
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> current_value;

        // update smallest_value if current_value is smaller
        if (current_value < smallest_value) {
            smallest_value = current_value;
        }
    }

    // display the smallest value
    std::cout << "The smallest value is: " << smallest_value << std::endl;
}
