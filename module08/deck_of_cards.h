// classes for card and deck of cards

#pragma once

#include <array>     // access to array class
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time to use as random number generation seed
#include <stdexcept> // for throwing exceptions
#include <string>    // access to string class

// card class
class Card {
  public:
    static constexpr int number_of_faces = 13; // number of unique card faces
    static constexpr int number_of_suits = 4;  // number of unique card suits
    static constexpr int number_of_cards = 52; // number of unique cards

    // enum for card faces
    enum Face {
        DEUCE,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };

    // enum for card suits
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    // constructor
    Card(Face face = ACE, Suit suit = SPADES) : face(face), suit(suit) {
    }

    // return card as a string
    std::string to_string() const {
        return faces[face] + " of " + suits[suit];
    }

  private:
    Face face; // face value of the card
    Suit suit; // suit value of the card

    // static array for face names
    inline static const std::array<std::string, number_of_faces> faces = {
        "Deuce", "Three", "Four", "Five",  "Six",  "Seven", "Eight",
        "Nine",  "Ten",   "Jack", "Queen", "King", "Ace"};

    // static array for suit names
    inline static const std::array<std::string, number_of_suits> suits = {
        "Clubs", "Diamonds", "Hearts", "Spades"};
};

// deck class
class DeckOfCards {
  public:
    // constructor to initialize deck
    DeckOfCards() {
        // seed random number generator on deck creation
        srand(static_cast<unsigned>(time(0)));
        // populate faces and suits
        int deck_index = 0; // current araray index to update
        for (int suit_index = 0; suit_index < Card::number_of_suits; ++suit_index) {
            for (int face_index = 0; face_index < Card::number_of_faces; ++face_index) {
                deck[deck_index++] = Card(static_cast<Card::Face>(face_index),
                                          static_cast<Card::Suit>(suit_index));
            }
        }
    }

    // shuffle the deck
    void shuffle() {
        for (std::size_t i = 0; i < deck.size(); ++i) {
            int j = rand() % deck.size();
            // swap card with random card from deck
            Card swap_card = deck[j];
            deck[j] = deck[i];
            deck[i] = swap_card;
        }
    }

    // deal the next card
    Card deal_card() {
        if (!more_cards())
            throw std::out_of_range("No cards remaining to be dealt.");
        return deck[current_card++];
    }

    // total number of cards in deck
    int number_of_cards() const {
        return static_cast<int>(deck.size());
    }

    // how many cards are left to deal
    int cards_remaining() const {
        return static_cast<int>(deck.size()) - current_card;
    }

    // are there more cards to deal
    bool more_cards() const {
        // return current_card < deck.size();
        return cards_remaining() > 0;
    }

  private:
    std::array<Card, Card::number_of_cards> deck;
    int current_card{0}; // index of the next card to deal
};
