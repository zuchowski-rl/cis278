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
    // this is done witout iteration as it is not covered by chapter 2
    cout << 0 << "\t" << 0 * 0 << "\t" << 0 * 0 * 0 << endl;
    cout << 1 << "\t" << 1 * 1 << "\t" << 1 * 1 * 1 << endl;
    cout << 2 << "\t" << 2 * 2 << "\t" << 2 * 2 * 2 << endl;
    cout << 3 << "\t" << 3 * 3 << "\t" << 3 * 3 * 3 << endl;
    cout << 4 << "\t" << 4 * 4 << "\t" << 4 * 4 * 4 << endl;
    cout << 5 << "\t" << 5 * 5 << "\t" << 5 * 5 * 5 << endl;
    cout << 6 << "\t" << 6 * 6 << "\t" << 6 * 6 * 6 << endl;
    cout << 7 << "\t" << 7 * 7 << "\t" << 7 * 7 * 7 << endl;
    cout << 8 << "\t" << 8 * 8 << "\t" << 8 * 8 * 8 << endl;
    cout << 9 << "\t" << 9 * 9 << "\t" << 9 * 9 * 9 << endl;
    cout << 10 << "\t" << 10 * 10 << "\t" << 10 * 10 * 10 << endl;

}
