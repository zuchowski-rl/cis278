// recursive function to check if a string is a palindrome

#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

bool is_palindrome(std::string in_string) {

    char left = in_string[0];
    char right = in_string[in_string.length() - 1];

    // check for base case
    if (in_string.length() == 1 || (in_string.length() == 2 && left == right)) {
        return true;
    }

    // if first and last element are equal, recursive call with the middle
    if (left == right) {
        std::string inner_string = in_string.substr(1, in_string.length() - 2);
        return is_palindrome(inner_string);
    }
    // else return false
    return false;
}

std::string prep_string(const std::string &in_string) {
    // remove non-alphanumeric characters convert to lower case
    std::string result;
    for (char character : in_string) {
        if (std::isalnum(character)) {
            result += std::tolower(character);
        }
    }
    return result;
}

int main() {
    // list of test strings
    std::string test_strings[] = {
        "radar",                     // simple palindrome
        "able was i ere i saw elba", // sentence palindrome
        "Madam I'm Adam.",           // palindrome with punctuation
        "xyz...",                    // not a palindrome
        "1234321",                   // numeric palindrome
        "a",                         // single character
    };

    // iterate over test strings and call is_palindrome
    for (const std::string &test_string : test_strings) {
        // print string and result
        std::cout << "\"" << test_string << "\" is";
        if (!is_palindrome(prep_string(test_string))) {
            std::cout << " not";
        }
        std::cout << " a palindrome." << std::endl;
    }
}
