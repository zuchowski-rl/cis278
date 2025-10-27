// demonstrate Polynomial class with overloaded operators

#include "Polynomial.h"
#include <iostream> // for access to output stream

int main() {
    // initial polynomials
    Polynomial poly_1 = {{3, 2}, {4, 1}, {2, 0}};   // 3x^2 + 4x + 2
    Polynomial poly_2 = {{1, 1}, {-5, 0}};          // x - 5
    Polynomial poly_3 = {{-2, 3}, {1, 2}, {-3, 0}}; // -2x^3 + x^2 - 3

    std::cout << "Initial Polynomials:\n";
    std::cout << "poly_1 = " << poly_1 << "\n";
    std::cout << "poly_2 = " << poly_2 << "\n";
    std::cout << "poly_3 = " << poly_3 << "\n\n";

    // addition
    std::cout << "Addition:" << "\n";
    Polynomial sum = poly_1 + poly_2;
    std::cout << "poly_1 + poly_2 = " << sum.to_string() << "\n\n";

    // subtraction
    std::cout << "Subtraction:" << "\n";
    Polynomial difference = poly_1 - poly_3;
    std::cout << "poly_1 - poly_3 = " << difference.to_string() << "\n\n";

    // multiplication
    std::cout << "Multiplication:" << "\n";
    Polynomial product = poly_2 * poly_3;
    std::cout << "poly_2 * poly_3 = " << product << "\n\n";

    // compound operators
    poly_1 += poly_2;
    std::cout << "after poly_1 += poly_2: poly_1 = " << poly_1 << "\n";

    poly_2 *= poly_1;
    std::cout << "after poly_2 *= poly_1: poly_2 = " << poly_2 << "\n";

    poly_3 -= poly_1;
    std::cout << "after poly_3 -= poly_1: poly_3 = " << poly_3 << "\n\n";

    // assignment
    std::cout << "Assignment:" << "\n";
    Polynomial poly_4;
    std::cout << "after creating default polynomial poly_4: poly_4 = " << poly_4 << "\n";
    poly_4 = poly_3;
    std::cout << "after assignment poly_4 = poly_3: poly_4 = " << poly_4 << "\n\n";
}
