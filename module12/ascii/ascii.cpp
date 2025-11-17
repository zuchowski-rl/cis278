#include <iomanip>
#include <iostream>

int main() {

    constexpr int column_width = 8;
    constexpr int ascii_start = 33;
    constexpr int ascii_end = 126;

    // display column headers
    std::cout << std::left << std::setw(column_width) << "DEC" << std::setw(column_width)
              << "OCT" << std::setw(column_width) << "HEX"
              << "CHAR" << std::endl;

    // loop from 33 to 126
    for (int i = ascii_start; i <= ascii_end; i++) {
        std::cout << std::dec << std::left << std::setw(column_width) << i; // decimal
        std::cout << std::oct << std::setw(column_width) << i;              // octal
        std::cout << std::hex << std::setw(column_width) << i;              // hexadecimal
        std::cout << std::dec << static_cast<char>(i) << std::endl;         // character
    }
}
