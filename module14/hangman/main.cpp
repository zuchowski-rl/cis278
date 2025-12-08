// driver to play the hangman game

#include "Hangman.h" // hangman class
#include <cstdlib>   // for random
#include <ctime>     // for seeding random number generation
#include <iostream>  // for access to input/output stream

int main() {
    // seed the random number generator
    std::srand(std::time(nullptr));

    // screen clearing sequence
    const std::string clear_screen = "\033[2J\033[H";

    // create instance of the game
    Hangman game;

    // sentinal for continuing to play
    std::string play_again = "yes";

    while (play_again == "yes") {

        // initialize a new game
        game.initialize_game();

        // game loop
        while (true) {

            // clear the screen
            std::cout << clear_screen;

            // display the hangman and current game status
            game.display_hangman();
            game.display_status();

            // prompt for user guess
            std::cout << "Guess a letter: ";
            char guess;
            std::cin >> guess;

            // process guess
            game.process_guess(guess);

            // check victory
            if (game.is_word_guessed()) {
                std::cout << "\nCongratulations, you guessed the word: " << game.get_selected_word()
                          << "\n";
                break;
            }

            // check if player is hanged
            if (game.is_hanged()) {
                // clear screen before final display
                std::cout << clear_screen;

                game.display_hangman();
                std::cout << "Game Over. The word was: " << game.get_selected_word() << "\n";
                break;
            }
        }

        // ask to play again
        std::cout << "\nPlay again? yes/no: ";
        std::cin >> play_again;
    }
}
