#pragma once

#include <string>

// class representing a single tool record
class ToolRecord {
  public:
    int id;
    char name[50];
    int quantity;
    double cost;

    ToolRecord();
    ToolRecord(int id, const std::string &name, int quantity, double cost);

    // getters
    int get_id() const;
    std::string get_name() const;
    int get_quantity() const;
    double get_cost() const;

    // setters
    void set_id(int id);
    void set_name(const std::string &name);
    void set_quantity(int quantity);
    void set_cost(double cost);
};
