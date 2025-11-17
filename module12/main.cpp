#include "Database.h"
#include <fstream>
#include <iostream>

// menu options
enum class Option { LIST = 1, UPDATE, NEW, DELETE, EXIT };

Option select_option() {
    // display menu options interface
    std::cout << "\n------ Hardware Store Inventory Menu ------\n";
    std::cout << "1. List all tools\n";
    std::cout << "2. Update a tool record\n";
    std::cout << "3. Add a new tool record\n";
    std::cout << "4. Delete a tool record\n";
    std::cout << "5. Exit\n";
    std::cout << "Select an option: ";

    int menu_option;
    std::cin >> menu_option;
    return static_cast<Option>(menu_option);
}

int main() {

    // create isntance of database class
    Database db("hardware.dat");

    Option selected_option; // store user selection

    // enable user to specify action
    while ((selected_option = select_option()) != Option::EXIT) {
        switch (selected_option) {
            case Option::LIST: // list all tools
                db.list_records();
                break;
            case Option::UPDATE: // update record
                db.update_record();
                break;
            case Option::NEW: // "create" record, using update record function
                db.update_record();
                break;
            case Option::DELETE: // delete existing record
                db.delete_record();
                break;
            default: // display error if user does not select a valid option
                std::cerr << "Invalid selection" << std::endl;
                break;
        }
    }
}
