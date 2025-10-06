// read pairs of numbers for product number and quantity
// look up prices with switch statement
// calculate and display total value of products sold

// provide access to input/output streams and stream manipulators
#include <iomanip>
#include <iostream>

// function to lookup price based on product number
double lookup_price(int product_number) {
    // price constants
    constexpr double default_price = 0.0;
    constexpr double product_1_price = 2.98;
    constexpr double product_2_price = 4.50;
    constexpr double product_3_price = 9.98;
    constexpr double product_4_price = 4.49;
    constexpr double product_5_price = 6.87;

    switch (product_number) {
        case 1:
            return product_1_price;
        case 2:
            return product_2_price;
        case 3:
            return product_3_price;
        case 4:
            return product_4_price;
        case 5:
            return product_5_price;
        default:
            std::cout << "Invalid product number." << std::endl;
            return default_price;
    }
}

int main() {
    // variables initialized on user input
    int product_number;
    int quantity_sold;
    // running total for final output
    double total_value{0.0};

    // set up formatting for output stream
    std::cout << std::fixed << std::setprecision(2);

    while (true) {

        // prompt for product number or sentinel
        std::cout << "Enter product number (1-5) or -1 to finish:";
        std::cin >> product_number;

        // end input on sentinel value
        if (product_number == -1) {
            break;
        }

        // get price from lookup function
        double price = lookup_price(product_number);

        // continue loop to skip invalid product/price
        if (price == 0) {
            continue;
        }

        // prompt for quantity, negative values allowed
        std::cout << "Enter the quantity sold: ";
        std::cin >> quantity_sold;

        // calculate item total
        double item_total = price * quantity_sold;
        // update running total with item
        total_value += item_total;

        std::cout << quantity_sold << " x Product #" << product_number << " @ "
                  << price << " : $" << item_total << std::endl;
    }

    // display final total
    std::cout << "\nTotal value of all products sold: $" << total_value
              << std::endl;
}
