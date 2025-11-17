#include "ToolRecord.h"

// default constructor
ToolRecord::ToolRecord() : id(0), name(""), quantity(0), cost(0.0) {
}

// constructor with parameters
ToolRecord::ToolRecord(int id, const std::string &name, int quantity, double cost)
    : id(id), quantity(quantity), cost(cost) {
    set_name(name);
}

// getters
int ToolRecord::get_id() const {
    return id;
}

std::string ToolRecord::get_name() const {
    return name;
}

int ToolRecord::get_quantity() const {
    return quantity;
}

double ToolRecord::get_cost() const {
    return cost;
}

// setters
void ToolRecord::set_id(int id) {
    this->id = id;
}

void ToolRecord::set_name(const std::string &name_string) {
    // copy at most 50 characters from string to name
    size_t length{name_string.size()};
    length = (length < 50 ? length : 49);
    name_string.copy(name, length);
    name[length] = '\0'; // append null character to  name
}

void ToolRecord::set_quantity(int quantity) {
    this->quantity = quantity;
}

void ToolRecord::set_cost(double cost) {
    this->cost = cost;
}
