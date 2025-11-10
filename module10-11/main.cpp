// driver program to demo the polymorphic use of functions of the Package class

// include package class headers
#include "OvernightPackage.h"
#include "Package.h"
#include "TwoDayPackage.h"

#include <iomanip>  // output stream manipulation
#include <iostream> // access to output stream
#include <vector>   // access to vector class

int main() {

    // constants for package creation
    const char *sender_name = "Herman Munster";
    const char *sender_address = "1313 Mockingbird Ln.";
    const char *sender_city = "Mockingbird Heights";
    const char *sender_state = "CA";
    const char *sender_zip = "90210";

    const char *recipient_name = "Homer Simpson";
    const char *recipient_address = "742 Evergreen Terrace";
    const char *recipient_city = "Springfield";
    const char *recipient_state = "IL";
    const char *recipient_zip = "49007";

    // constants for weight and prices
    constexpr double package_1_weight{10.5};
    constexpr double package_2_weight{12.75};
    constexpr double package_3_weight{9.2};
    constexpr double package_4_weight{20.5};

    constexpr double cost_per_oz(0.70);
    constexpr double flat_fee{6.99};
    constexpr double extra_fee{1.75};

    // create some packages of both types, rotating sender and recipient
    TwoDayPackage pkg_1(sender_name, sender_address, sender_city, sender_state,
                        sender_zip, recipient_name, recipient_address, recipient_city,
                        recipient_state, recipient_zip, package_1_weight, cost_per_oz,
                        flat_fee);

    OvernightPackage pkg_2(sender_name, sender_address, sender_city, sender_state,
                           sender_zip, recipient_name, recipient_address, recipient_city,
                           recipient_state, recipient_zip, package_2_weight, cost_per_oz,
                           extra_fee);

    TwoDayPackage pkg_3(recipient_name, recipient_address, recipient_city,
                        recipient_state, recipient_zip, sender_name, sender_address,
                        sender_city, sender_state, sender_zip, package_3_weight,
                        cost_per_oz, flat_fee);

    OvernightPackage pkg_4(recipient_name, recipient_address, recipient_city,
                           recipient_state, recipient_zip, sender_name, sender_address,
                           sender_city, sender_state, sender_zip, package_4_weight,
                           cost_per_oz, extra_fee);

    // store all package pointers in a vector of base class pointers
    std::vector<Package *> packages{&pkg_1, &pkg_2, &pkg_3, &pkg_4};

    // variable to hold running total
    double total_cost{0.0};

    // use std::fixed and std::setprecision for money formatting
    std::cout << std::fixed << std::setprecision(2);

    // print info for each package
    for (const Package *pkg : packages) {
        std::cout << "---------------------------------------\n";
        std::cout << "Sender:\n  ";
        std::cout << pkg->get_sender_name() << "\n  " << pkg->get_sender_address()
                  << "\n  " << pkg->get_sender_city() << ", " << pkg->get_sender_state()
                  << " " << pkg->get_sender_zip() << "\n\n";

        std::cout << "Recipient:\n  ";
        std::cout << pkg->get_recipient_name() << "\n  " << pkg->get_recipient_address()
                  << "\n  " << pkg->get_recipient_city() << ", "
                  << pkg->get_recipient_state() << " " << pkg->get_recipient_zip()
                  << "\n";

        // polymorphic call to calculate_cost, uses overidden function in derived classes
        double cost = pkg->calculate_cost();
        std::cout << "\nShipping cost: $" << cost << "\n";
        std::cout << "---------------------------------------\n";

        // add package cost to total_cost
        total_cost += cost;
    }

    // display grand total for all packages
    std::cout << "\nTotal Shipping cost: $" << total_cost << std::endl;
}
