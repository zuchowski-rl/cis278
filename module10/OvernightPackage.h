// defines a OvernightPackage class derived from base Package class
// used for calculating shipping costs based on package weight with additonl per ounce fee

#pragma once

#include "Package.h"

#include <string> // access to string class

// derived class for overnight packages
class OvernightPackage : public Package {
  private:
    double extra_fee_per_oz;

  public:
    OvernightPackage(const std::string &sender_name, const std::string &sender_address,
                     const std::string &sender_city, const std::string &sender_state,
                     const std::string &sender_zip, const std::string &recipient_name,
                     const std::string &recipient_address,
                     const std::string &recipient_city,
                     const std::string &recipient_state, const std::string &recipient_zip,
                     double weight_oz, double cost_per_oz, double extra_fee);

    double calculate_cost() const override;
    void print_details() const override;
};
