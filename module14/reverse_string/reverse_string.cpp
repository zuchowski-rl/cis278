// reverse a string and change case for each character

#include <cctype>   // for character manipulation functions
#include <iostream> // access to input/output streams
#include <string>   // access to string class

std::string reverse_string(const std::string &input) {
    std::string result;

    // loop over string in reverse
    for (int i = input.length() - 1; i >= 0; --i) {
        char character = input[i];

        // swap case
        if (std::islower(character)) {
            character = std::toupper(character);
        } else if (std::isupper(character)) {
            character = std::tolower(character);
        }

        // build new string
        result += character;
    }

    return result;
}

int main() {
    std::string user_input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, user_input);

    std::string output = reverse_string(user_input);

    std::cout << "Transformed and reversed string: " << output << std::endl;
}
