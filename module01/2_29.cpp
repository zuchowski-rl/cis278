// Module 01 Chapter 02 Exercise 2.29
// Using the techniques of this chapter, write a program that
// calculates the squares and cubes of the integers from 0 to 10.
// Use tabs to print the following neatly formatted table of values

#include <iostream> // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

int main() {

    // display table header
    cout << "integer\tsquare\tcube\n";

    // display a tab separated row per integer from 1 to 10 with square and cube
    for (int i = 0; i <= 10; ++i) {
        cout << i << "\t" << i * i << "\t" << i * i * i << endl;
    }
}
