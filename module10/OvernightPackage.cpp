// OvernightPackage implementation
#include "OvernightPackage.h"

#include <iomanip>   // access to stream manipulators
#include <iostream>  // access to output stream
#include <stdexcept> // for throwing exceptions
#include <string>    // access to string class

// OvernightPackage consutructor
OvernightPackage::OvernightPackage(
    const std::string &sender_name, const std::string &sender_address,
    const std::string &sender_city, const std::string &sender_state,
    const std::string &sender_zip, const std::string &recipient_name,
    const std::string &recipient_address, const std::string &recipient_city,
    const std::string &recipient_state, const std::string &recipient_zip,
    double weight_oz, double cost_per_oz, double extra_fee)
    : Package(sender_name, sender_address, sender_city, sender_state, sender_zip,
              recipient_name, recipient_address, recipient_city, recipient_state,
              recipient_zip, weight_oz, cost_per_oz),
      extra_fee_per_oz(extra_fee) {

    // validate extra fee is greater than 0
    if (extra_fee_per_oz <= 0.0) {
        throw std::invalid_argument("Extra fee must be greater than 0.0");
    }
}

// calculate cost for an OvernightPackage
double OvernightPackage::calculate_cost() const {
    double total_cost_per_oz = cost_per_oz + extra_fee_per_oz;
    return weight_oz * total_cost_per_oz;
}

// print details for an OvernightPackage
void OvernightPackage::print_details() const {
    Package::print_details();
    std::cout << std::setw(LABEL_WIDTH) << std::left
              << "Including extra fee per oz:" << std::right << "$" << extra_fee_per_oz
              << "\n";
}
