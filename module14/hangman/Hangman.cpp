// terminal hangman game implementation

#include "Hangman.h"
#include <algorithm> // for find algorithm
#include <chrono>    // access to seconds for sleeping
#include <fstream>   // for file stream
#include <iostream>  // accesss to input/output streams
#include <string>    // access to the string class
#include <thread>    // access to sleep

// constructor
Hangman::Hangman(const std::string &filename) {
    load_words(filename);
}

// load words from the file
bool Hangman::load_words(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open word file: " << filename << "\n";
        return false;
    }

    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();
    return !words.empty();
}

// choose a random word and reset game state
void Hangman::initialize_game() {
    if (words.empty()) {
        std::cout << "Error: No words loaded.\n";
        return;
    }

    int random_index = rand() % words.size();
    selected_word = words[random_index];

    display_word = std::string(selected_word.length(), 'X');
    guesses.clear();
    wrong_guess_count = 0;
}

// return the selected word
std::string Hangman::get_selected_word() {
    return selected_word;
}

// show the hangman based on wrong guess count
void Hangman::display_hangman() {
    std::cout << "\n" << hangman_display_strings[wrong_guess_count] << "\n\n";
}

// display masked word and user guesses
void Hangman::display_status() {
    std::cout << "Guess this word:  " << display_word << "\n";
    std::cout << "Guesses so far: ";

    for (char character : guesses)
        std::cout << character << " ";

    std::cout << "\n\n";
}

// process a guess
bool Hangman::process_guess(char guess) {
    guess = std::tolower(guess);

    // check for repeated guess
    if (std::find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
        std::cout << "That was already guessed.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return true;
    }

    guesses.push_back(guess);

    bool correct = false;

    // reveal matching letters
    for (size_t i = 0; i < selected_word.length(); ++i) {
        if (std::tolower(selected_word[i]) == guess) {
            display_word[i] = selected_word[i];
            correct = true;
        }
    }

    if (correct) {
        std::cout << "Yes...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
        wrong_guess_count++;
        std::cout << "No...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return correct;
}

// check if word fully guessed
bool Hangman::is_word_guessed() {
    return display_word == selected_word;
}

// check if player reached max wrong guesses
bool Hangman::is_hanged() {
    return wrong_guess_count >= 7;
}
