// defines a base Package class
// used for calculating shipping costs based on package weight

#pragma once

#include <string> // access to string class

// base class for packages
class Package {
  protected:
    // sender info
    std::string sender_name;
    std::string sender_address;
    std::string sender_city;
    std::string sender_state;
    std::string sender_zip;

    // recipient info
    std::string recipient_name;
    std::string recipient_address;
    std::string recipient_city;
    std::string recipient_state;
    std::string recipient_zip;

    // package info
    double weight_oz;   // in ounces
    double cost_per_oz; // cost per ounce

    // label width for printing package info
    static constexpr int LABEL_WIDTH{30};

  public:
    Package(const std::string &sender_name, const std::string &sender_address,
            const std::string &sender_city, const std::string &sender_state,
            const std::string &sender_zip, const std::string &recipient_name,
            const std::string &recipient_address, const std::string &recipient_city,
            const std::string &recipient_state, const std::string &recipient_zip,
            double weight_oz, double cost_per_oz);

    virtual ~Package() {
    }

    virtual double calculate_cost() const;
    virtual void print_details() const;
};
