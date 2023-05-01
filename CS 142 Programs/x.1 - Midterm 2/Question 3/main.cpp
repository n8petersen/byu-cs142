#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double SALES_TAX = 0.07;  // sales tax percentage

int main() {
    double amount;
    double subTotal = 0.0;
    double salesTax = 0.0;
    double total = 0.0;

    do {                                // Takes user input for each cost, and adds to subtotal until user enters '0.0'
        cin  >> amount;
        subTotal = subTotal + amount;
    } while (amount != 0.0);

    salesTax = subTotal * SALES_TAX;    // Calculates sales tax based on subtotal and sales tax percentage
    total = subTotal + salesTax;        // Calculates total based

    cout << "The receipt for your order will have these totals" << endl << endl;    // Outputs the totals and tax amount
    cout << fixed << setprecision(2) << "subtotal: $" << subTotal << endl;
    cout << fixed << setprecision(2) << "sales tax: $" << salesTax << endl;
    cout << fixed << setprecision(2) << "total: $" << total << endl;

    return 0;
}
