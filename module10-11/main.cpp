// driver program to demo the Package class and its derived classes

// include package class headers
#include "OvernightPackage.h"
#include "Package.h"
#include "TwoDayPackage.h"

#include <iostream> // access to output stream

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
    constexpr double package_weight{10.5};
    constexpr double cost_per_oz(0.70);
    constexpr double flat_fee{6.99};
    constexpr double extra_fee{1.75};

    // create some packages
    // standard package
    Package standard_pkg(sender_name, sender_address, sender_city, sender_state,
                         sender_zip, recipient_name, recipient_address, recipient_city,
                         recipient_state, recipient_zip, package_weight, cost_per_oz);

    // two day package
    TwoDayPackage two_day_pkg(sender_name, sender_address, sender_city, sender_state,
                              sender_zip, recipient_name, recipient_address,
                              recipient_city, recipient_state, recipient_zip,
                              package_weight, cost_per_oz, flat_fee);

    // overnight package
    OvernightPackage overnight_pkg(sender_name, sender_address, sender_city, sender_state,
                                   sender_zip, recipient_name, recipient_address,
                                   recipient_city, recipient_state, recipient_zip,
                                   package_weight, cost_per_oz, extra_fee);

    // display package shipping info and prices
    std::cout << "Standard Package:" << std::endl;
    std::cout << "---------------------------------------\n";
    standard_pkg.print_details();
    std::cout << std::endl;

    std::cout << "Two Day Package:" << std::endl;
    std::cout << "----------------------------------------\n";
    two_day_pkg.print_details();
    std::cout << std::endl;

    std::cout << "Overnight Package:" << std::endl;
    std::cout << "----------------------------------------\n";
    overnight_pkg.print_details();
    std::cout << std::endl;
}
