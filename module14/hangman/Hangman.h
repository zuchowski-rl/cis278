// hangman class header

#pragma once

#include <string> // access to the string class
#include <vector> // access to the vector class

class Hangman {
  private:
    // list of all words loaded from file
    std::vector<std::string> words;

    // selected word for the current game
    std::string selected_word;

    // masked word shown to the user
    std::string display_word;

    // list of all guessed characters
    std::vector<char> guesses;

    // number of incorrect guesses
    int wrong_guess_count{0};

    // strings to display hangman for each number of failed guesses
    const std::vector<std::string> hangman_display_strings = {"",
                                                              " O ",
                                                              " O \n | ",
                                                              " O \n/| ",
                                                              " O \n/|\\",
                                                              " O \n/|\\\n | ",
                                                              " O \n/|\\\n | \n/  ",
                                                              " O \n/|\\\n | \n/ \\"};

  public:
    // constructor with default filename
    Hangman(const std::string &filename = "words.txt");

    // load words from a file into the vector
    bool load_words(const std::string &filename);

    // select a random word and reset game values
    void initialize_game();

    // return the selected word
    std::string get_selected_word();

    // display the hangman image for the current wrong guess count
    void display_hangman();

    // show masked word and guessed letters
    void display_status();

    // handle a character guess
    bool process_guess(char guess);

    // return true if user has guessed the word
    bool is_word_guessed();

    // return true if player has reached max wrong guesses
    bool is_hanged();
};
