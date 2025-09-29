// computer assisted instruction command line app
// generates random multiplication questions for one digit integers

#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time to use as random number generation seed
#include <iostream> // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

// function to generate numbers for each question
void generate_question(int &factor_1, int &factor_2) {

    // constants to control range of random numbers
    const int SHIFTING_VALUE{1};
    const int SCALING_FACTOR{9};
    // generates two numbers between 1 and 9, updates references
    factor_1 = SHIFTING_VALUE + rand() % SCALING_FACTOR;
    factor_2 = SHIFTING_VALUE + rand() % SCALING_FACTOR;
}

// function to generate and prompt each question
bool prompt_question(int factor_1, int factor_2) {

    int answer;

    // loop until a correct answer or sentinel is entered
    while (true) {

        cout << "How much is " << factor_1 << " times " << factor_2 << "? ";
        cout << "(Enter -1 to exit): ";
        cin >> answer;

        if (answer == -1) {
            return false; // sentinel entered
        }

        if (answer == factor_1 * factor_2) {
            cout << "Very Good!" << endl << endl;
            return true; // correct answer
        } else {
            cout << "No. Please try again." << endl;
        }
    }
}

int main() {
    // seed random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // declare variables to hold factors for question
    int factor_1, factor_2;
    // randomize the factors
    generate_question(factor_1, factor_2);

    // prompt a new quetion on each loop
    while (prompt_question(factor_1, factor_2)) {
        // generate new random numbers for the next question
        generate_question(factor_1, factor_2);
    }
}
