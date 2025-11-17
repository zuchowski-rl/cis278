#include "Database.h"
#include <fstream>  // for file i/o
#include <iomanip>  // stream manipualtion
#include <iostream> //

Database::Database(const std::string &file_name) : file_name(file_name) {

    // open file
    this->file.open(file_name,
                    std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    // exit program if fstream cannot open file
    if (!file) {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    // intitialize file with empty records
    initialize_file();

    // seed with sample data
    seed_initial_records();
}

void Database::initialize_file() {

    ToolRecord blank_record;

    // populate with 100 blank records
    for (int i = 0; i < 100; i++)
        file.write(reinterpret_cast<const char *>(&blank_record), sizeof(ToolRecord));

    // reset
    file.clear();
    file.seekg(0);
    file.seekp(0);
}

void Database::seed_initial_records() {

    struct Seed {
        int id;
        std::string name;
        int quantity;
        double cost;
    };

    Seed seeds[] = {{3, "Electric sander", 7, 57.98}, {17, "Hammer", 76, 11.99},
                    {24, "Jig saw", 21, 11.00},       {39, "lawn mower", 3, 79.50},
                    {56, "Power saw", 18, 99.99},     {68, "Screwdriver", 106, 6.99},
                    {77, "Sledge hammer", 11, 21.50}, {83, "Wrench", 34, 7.50}};

    for (auto &seed : seeds) {
        ToolRecord record;
        record.id = seed.id;
        record.set_name(seed.name);
        record.quantity = seed.quantity;
        record.cost = seed.cost;

        file.seekp((seed.id - 1) * sizeof(ToolRecord));
        file.write(reinterpret_cast<const char *>(&record), sizeof(ToolRecord));
    }

    // reset
    file.clear();
    file.seekg(0);
    file.seekp(0);
}

void Database::list_records() {

    ToolRecord record;

    std::cout << std::left << std::setw(6) << "ID" << std::setw(20) << "Tool Name"
              << std::setw(10) << "Quantity" << std::setw(10) << "Cost" << std::endl;

    for (int i = 0; i < 100; i++) {
        file.read(reinterpret_cast<char *>(&record), sizeof(ToolRecord));

        if (record.id != 0) {
            std::cout << std::left << std::setw(6) << record.id << std::setw(20)
                      << record.name << std::setw(10) << record.quantity << "$"
                      << std::fixed << std::setprecision(2) << record.cost << std::endl;
        }
    }

    file.clear();
    file.seekg(0);
    file.seekp(0);
}

void Database::update_record() {

    ToolRecord record;
    int id;

    std::cout << "Enter tool id (1-100): ";
    std::cin >> id;

    if (id < 1 || id > 100) {
        std::cout << "Invalid ID.\n";
        return;
    }

    std::cout << "Enter tool name: ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter quantity: ";
    std::cin >> record.quantity;

    std::cout << "Enter cost: ";
    std::cin >> record.cost;

    record.id = id;
    record.set_name(name);

    file.seekp((id - 1) * sizeof(ToolRecord));
    file.write(reinterpret_cast<const char *>(&record), sizeof(ToolRecord));

    file.clear();
    file.seekg(0);
    file.seekp(0);
    std::cout << "Record updated.\n";
}

void Database::delete_record() {

    ToolRecord blank_record;
    int id;

    std::cout << "Enter tool ID to delete (1-100): ";
    std::cin >> id;

    if (id < 1 || id > 100) {
        std::cout << "Invalid ID.\n";
        return;
    }

    file.seekp((id - 1) * sizeof(ToolRecord));
    file.write(reinterpret_cast<const char *>(&blank_record), sizeof(ToolRecord));

    file.clear();
    file.seekg(0);
    file.seekp(0);
    std::cout << "Record deleted.\n";
}
