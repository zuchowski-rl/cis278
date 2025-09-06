// create a custom Invoice class for item purchases at a store
// with data members for part number, description, price, and quantity
// and a member function that calculates the invoice total

// provide access to input/output streams and string class
#include <iostream>
#include <string>

class Invoice {
  private:
    std::string part_number;      // data member for part number
    std::string part_description; // data member for part description
    int quantity;                 // data member for quantity
    int price_per_item;           // data member for price

  public:
    // constructor
    Invoice(std::string part_number, std::string part_description, int quantity,
            int price_per_item)
        : part_number{part_number}, part_description{part_description} {
        set_quantity(quantity);
        set_price_per_item(price_per_item);
    }

    // setters
    void set_part_number(const std::string &part_number) {
        this->part_number = part_number;
    }

    void set_part_description(const std::string &part_description) {
        this->part_description = part_description;
    }

    void set_quantity(int quantity) {
        // validate positive value and set neagtives to 0
        if (quantity > 0) {
            this->quantity = quantity;
        } else {
            std::cout << "Invalid quantity entered, deafulting to 0.\n";
            this->quantity = 0;
        }
    }

    void set_price_per_item(int price_per_item) {
        // validate positive value and set neagtives to 0
        if (price_per_item > 0) {
            this->price_per_item = price_per_item;
        } else {
            std::cout << "Invalid price entered, deafulting to 0.\n";
            this->price_per_item = 0;
        }
    }

    // getters
    std::string get_part_number() const {
        return part_number;
    }

    std::string get_part_description() const {
        return part_description;
    }

    int get_quantity() const {
        return quantity;
    }

    int get_price_per_item() const {
        return price_per_item;
    }

    // calculates invoice total
    int get_invoice_amount() const {
        return quantity * price_per_item;
    }
};
