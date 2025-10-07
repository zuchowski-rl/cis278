// computer assisted instruction command line app
// generates random multiplication questions for one digit integers
// provides varied feedback to reduce student fatigue

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

// function to display a random response to a correct answer
string generate_correct_response() {

    // constants to control range of random numbers
    const int SHIFTING_VALUE{1};
    const int SCALING_FACTOR{4};
    // generates a choice between 1 and 4
    int choice = SHIFTING_VALUE + rand() % SCALING_FACTOR;

    switch (choice) {
        case 1:
            return "Very good!";
        case 2:
            return "Excellent!";
        case 3:
            return "Nice work!";
        case 4:
            return "Keep up the good work!";
        default:
            return "";
    }
}

// function to display a random response to an incorrect answer
string generate_incorrect_response() {

    // constants to control range of random numbers
    const int SHIFTING_VALUE{1};
    const int SCALING_FACTOR{4};
    // generates a choice between 1 and 4
    int choice = SHIFTING_VALUE + rand() % SCALING_FACTOR;

    switch (choice) {
        case 1:
            return "No. Please try again.";
        case 2:
            return "Wrong. Try once more.";
        case 3:
            return "Don't give up!";
        case 4:
            return "No. Keep trying.";
        default:
            return "";
    }
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
            cout << generate_correct_response() << endl;
            return true;
        } else {
            cout << generate_incorrect_response() << endl;
        }
    }
}

int main() {
    // seed random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // declare variables to hold factors for question
    int factor_1{0}, factor_2{0};
    // randomize the factors
    generate_question(factor_1, factor_2);

    // prompt a new quetion on each loop
    while (prompt_question(factor_1, factor_2)) {
        // generate new random numbers for the next question
        generate_question(factor_1, factor_2);
    }
}
