// Package class implementation
#include "Package.h"

#include <iomanip>   // access to stream manipulators
#include <iostream>  // access to output stream
#include <stdexcept> // for throwing exceptions
#include <string>    // access to string class

// package class constructor
Package::Package(const std::string &sender_name, const std::string &sender_address,
                 const std::string &sender_city, const std::string &sender_state,
                 const std::string &sender_zip, const std::string &recipient_name,
                 const std::string &recipient_address, const std::string &recipient_city,
                 const std::string &recipient_state, const std::string &recipient_zip,
                 double weight_oz, double cost_per_oz)
    : sender_name(sender_name), sender_address(sender_address), sender_city(sender_city),
      sender_state(sender_state), sender_zip(sender_zip), recipient_name(recipient_name),
      recipient_address(recipient_address), recipient_city(recipient_city),
      recipient_state(recipient_state), recipient_zip(recipient_zip),
      weight_oz(weight_oz), cost_per_oz(cost_per_oz) {

    // validate weight is greater than 0
    if (weight_oz <= 0.0) {
        throw std::invalid_argument("Weight must be greater than 0.0");
    }
    // validate cost per oz is greater than 0
    if (cost_per_oz <= 0.0) {
        throw std::invalid_argument("Cost per ounce must be greater than 0.0");
    }
}

// calculate cost for a package
double Package::calculate_cost() const {
    return weight_oz * cost_per_oz;
}

// sender info getters
const std::string &Package::get_sender_name() const {
    return sender_name;
}
const std::string &Package::get_sender_address() const {
    return sender_address;
}
const std::string &Package::get_sender_city() const {
    return sender_city;
}
const std::string &Package::get_sender_state() const {
    return sender_state;
}
const std::string &Package::get_sender_zip() const {
    return sender_zip;
}

// recipient info getters
const std::string &Package::get_recipient_name() const {
    return recipient_name;
}
const std::string &Package::get_recipient_address() const {
    return recipient_address;
}
const std::string &Package::get_recipient_city() const {
    return recipient_city;
}
const std::string &Package::get_recipient_state() const {
    return recipient_state;
}
const std::string &Package::get_recipient_zip() const {
    return recipient_zip;
}

// // print package details
void Package::print_details() const {
    std::cout << std::fixed << std::setprecision(2);

    // sender address
    std::cout << "Sender:\n  " << sender_name << "\n  " << sender_address << "\n  "
              << sender_city << ", " << sender_state << " " << sender_zip << "\n\n";

    // recipient address
    std::cout << "Recipient:\n  " << recipient_name << "\n  " << recipient_address
              << "\n  " << recipient_city << ", " << recipient_state << " "
              << recipient_zip << "\n\n";

    // package info
    std::cout << std::setw(LABEL_WIDTH) << std::left << "Weight:" << std::right
              << weight_oz << " oz\n";
    std::cout << std::setw(LABEL_WIDTH) << std::left << "Cost per ounce:" << std::right
              << "$" << cost_per_oz << "\n";
    std::cout << std::setw(LABEL_WIDTH) << std::left
              << "Total Shipping cost:" << std::right << "$" << calculate_cost() << "\n";
}
