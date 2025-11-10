// TwoDayPackage implementation
#include "TwoDayPackage.h"

#include <iomanip>   // access to stream manipulators
#include <iostream>  // access to output stream
#include <stdexcept> // for throwing exceptions
#include <string>    // access to string class

// TwoDayPackage constructor
TwoDayPackage::TwoDayPackage(
    const std::string &sender_name, const std::string &sender_address,
    const std::string &sender_city, const std::string &sender_state,
    const std::string &sender_zip, const std::string &recipient_name,
    const std::string &recipient_address, const std::string &recipient_city,
    const std::string &recipient_state, const std::string &recipient_zip,
    double weight_oz, double cost_per_oz, double flat_fee)
    : Package(sender_name, sender_address, sender_city, sender_state, sender_zip,
              recipient_name, recipient_address, recipient_city, recipient_state,
              recipient_zip, weight_oz, cost_per_oz),
      flat_fee(flat_fee) {

    // validate flat fee is greater than 0
    if (flat_fee <= 0.0) {
        throw std::invalid_argument("Flat Fee must be greater than 0.0");
    }
}

// calculate cost for a TwoDayPackage
double TwoDayPackage::calculate_cost() const {
    return Package::calculate_cost() + flat_fee;
}

// print details for a TwoDayPackage
void TwoDayPackage::print_details() const {
    Package::print_details();
    std::cout << std::setw(LABEL_WIDTH) << std::left
              << "Including flat fee:" << std::right << "$" << flat_fee << "\n";
}
