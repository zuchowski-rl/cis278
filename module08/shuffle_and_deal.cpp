// driver to demonstrate the card and deck of cards classes
// deals all cards from a deck and displays them in the terminal

#include "deck_of_cards.h"

// provide access to input/output streams and stream manipulators
#include <iomanip>
#include <iostream>

int main() {
    // initialize and shuffle deck
    DeckOfCards deck;
    deck.shuffle();

    // constants tto control display of cards
    constexpr int display_columns = 4;
    constexpr int column_width = 20;

    // deal all cards
    for (int i = 0; deck.more_cards(); ++i) {
        std::cout << std::left << std::setw(column_width) << deck.deal_card().to_string();
        if ((i + 1) % display_columns == 0) {
            // go to next row
            std::cout << std::endl;
        }
    }
}
