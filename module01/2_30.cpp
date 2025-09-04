// Module 01 Chapter 02 Exercise 2.30
// Create a BMI calculator application that reads the user’s weight in pounds
// and height in inches, then calculates and displays the user’s body mass index.
// Also, the application should display the following information from
// the Department of Health and Human Services/National Institutes of Health
// so the user can evaluate his/her BMI

#include <iostream> // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

int main() {

    // display bmi information from the HHS/NIH
    cout << "BMI Values\n";
    cout << "Underweight:\tless than 18.5\n";
    cout << "Normal:\t\tbetween 18.5 and 24.9\n";
    cout << "Overweight:\tbetween 25 abd 29.9\n";
    cout << "Obese:\t\t30 or greater\n";

    // declare variables to hold user input
    int weight_lbs;
    int height_inches;

    // constant factor for converting formula to use imperial units
    const int BMI_IMPERIAL_CONVERSION_FACTOR = 703;

    // prompt for and assign user input to variables
    cout << "Enter height in inches: ";
    cin >> height_inches;
    cout << "Enter weight in pounds: ";
    cin >> weight_lbs;

    // calculate bmi as a whole number using integer division
    int bmi = (weight_lbs * BMI_IMPERIAL_CONVERSION_FACTOR) /
              (height_inches * height_inches);

    // disply bmi
    cout << "The calculated BMI is " << bmi << endl;
}
