// Module 01 Chapter 02 Exercise 2.19
// Write a program that inputs three integers from the keyboard and 
// prints the sum, average, product, smallest and largest of these numbers.

#include <iostream> // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

int main() {
    
    // declare variables that will hold user input
    int number_1;
    int number_2;
    int number_3;
    
    // prompt for and collect user input
    cout << "Input three different integers: ";
    cin >> number_1 >> number_2 >> number_3;

    // declare and calculate variables for output
    // this is done without separate functions because they are not yet covered
    int sum = number_1 + number_2 + number_3;
    int average = sum / 3;
    int product = number_1 * number_2 * number_3;

    // calculate min without algorithm header, using if statements
    // assume number_1 is smallest
    int smallest = number_1;

    // replace smallest with number_2 if it is less
    if (number_2 < smallest) {
        smallest = number_2;
    }

    // replace smallest with number_3 if it is less
    if (number_3 < smallest) {
        smallest = number_3;
    }

    // calculate max without algorithm header, using if statements
    // assume number_1 is largest
    int largest = number_1;

    // replace largest with number_2 if it is greater
    if (number_2 > largest) {
        largest = number_2;
    }

    // replace largest with number_3 if it is greater
    if (number_3 > largest) {
        largest = number_3;
    }

    // display calculated output
    cout << "Sum is " << sum << endl;
    cout << "Average is " << average << endl;
    cout << "Product is " << product << endl;
    cout << "Smallest is " << smallest << endl;
    cout << "Largest is " << largest << endl;
    
}
