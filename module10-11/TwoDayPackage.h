// defines a TwoDayPackage class derived from base Package class
// used for calculating shipping costs based on package weight with an added flat fee

#pragma once

#include "Package.h"

#include <string> // access to string class

// derived class for two day packages
class TwoDayPackage : public Package {
  private:
    double flat_fee{0.0};

  public:
    TwoDayPackage(const std::string &sender_name, const std::string &sender_address,
                  const std::string &sender_city, const std::string &sender_state,
                  const std::string &sender_zip, const std::string &recipient_name,
                  const std::string &recipient_address, const std::string &recipient_city,
                  const std::string &recipient_state, const std::string &recipient_zip,
                  double weight_oz, double cost_per_oz, double flat_fee);

    double calculate_cost() const override;
    void print_details() const override;
};
