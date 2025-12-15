#pragma once

#include "StudentDatabase.h"
#include <functional> // access to function type
#include <string>     // access to string class
#include <vector>     // access to vector class

// structure for menu command
struct MenuCommand {
    std::string key;              // key to press
    std::string description;      // description of action
    std::function<void()> action; // function to call
};

class Menu {
  private:
    // student database instance
    StudentDatabase database;
    // all menu commands
    std::vector<MenuCommand> commands;

    // builds all menu items
    void setup_menu();
    // clears screen
    void clear_screen();

  public:
    // constructor initializes menu
    Menu();

    // displays the menu options
    void display_menu();

    // display menu and execute one user selection
    bool run();
};
