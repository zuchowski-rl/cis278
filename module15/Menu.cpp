#include "Menu.h"
#include <algorithm> // for find algorithm to match input to menu item
#include <cctype>    // access to toupper character transformation
#include <iostream>  // access to input/output streams

Menu::Menu() {
    // initialize menu items
    setup_menu();
}

void Menu::clear_screen() {
    // screen clearing sequence
    const std::string clear_screen = "\033[2J\033[H";
    std::cout << clear_screen;
}

// configure menu items
void Menu::setup_menu() {
    commands = {
        {"S", "select and display all students records", [&]() { database.display_students(); }},
        {"D", "delete a student by ID#", [&]() { database.delete_student(); }},
        {"U", "update a student's graduation year", [&]() { database.update_graduation_year(); }},
        {"I", "insert a new student", [&]() { database.insert_student(); }},
        {"Q", "quit", {}}};
}

void Menu::display_menu() {
    for (const auto &item : commands) {
        std::cout << "(" << item.key << ") " << item.description << '\n';
    }
}

bool Menu::run() {
    clear_screen();

    display_menu();

    std::cout << "\nEnter choice: ";
    std::string input;
    std::cin >> input;

    // convert input to uppercase
    for (auto &c : input)
        c = std::toupper(c);

    // find matching command
    auto command = std::find_if(commands.begin(), commands.end(),
                                [&](const MenuCommand &cmd) { return cmd.key == input; });

    if (command == commands.end()) {
        std::cout << "Invalid option\n"; // no matching command found
    } else if (command->key == "Q") {
        std::cout << "Exiting program\n";
        return false;
    } else {
        command->action(); // call function for found command
    }

    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();

    return true; // continue running
}
