// calculate and display the product of all odd numbers from 1 to 15

#include <iostream> // allow access to input/output streams

int main() {

    // variable to hold running product, initialized to 1
    int product{1};

    // loop through all odd numbers from 1 to 15
    for (int number = 1; number <= 15; number += 2) {
        // update product
        product *= number;
    }

    // display results
    std::cout << "The product of odd integers from 1 to 15 is: " << product
              << std::endl;
}
