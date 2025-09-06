// test and demonstrate functionality fo the Invoice class

#include "Invoice.h" // include custom Invoice class
#include <iostream>  // allow access to input/output streams

using namespace std; // allow direct access to std namespace members

int main() {
    // create invoice object with valid values
    cout << "Invoice 1, 10 Hammers @ 25 price: \n";
    Invoice invoice_1("4jd9nadf8", "Hammer", 10, 25);

    // display invoice 1 data
    cout << "Part Number: " << invoice_1.get_part_number() << endl;
    cout << "Description: " << invoice_1.get_part_description() << endl;
    cout << "Quantity: " << invoice_1.get_quantity() << endl;
    cout << "Price per item: " << invoice_1.get_price_per_item() << endl;
    cout << "Total Invoice Amount: " << invoice_1.get_invoice_amount() << endl;

    cout << "\n";

    // create invoice object with invalid values
    cout << "Invoice 2, -1 Wrenches at -1 price: \n";
    Invoice invoice_2("sd57nrhg4", "Wrench", -1, -1);

    // display invoice 2 data
    cout << "Part Number: " << invoice_2.get_part_number() << endl;
    cout << "Description: " << invoice_2.get_part_description() << endl;
    cout << "Quantity: " << invoice_2.get_quantity() << endl;
    cout << "Price per item: " << invoice_2.get_price_per_item() << endl;
    cout << "Total Invoice Amount: " << invoice_2.get_invoice_amount() << endl;
}
