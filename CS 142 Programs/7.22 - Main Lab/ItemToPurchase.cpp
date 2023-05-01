#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

//CONSTRUCTORS
ItemToPurchase::ItemToPurchase() { // Default Constructor
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string productName, string productDescription, double productPrice, int productQuantity) {// Parameterized Constructor
    itemName = productName;
    itemDescription = productDescription;
    itemPrice = productPrice;
    itemQuantity = productQuantity;
}
// FUNCTIONS
void ItemToPurchase::SetName(std::string productName) { // Sets the name of a products
    itemName = productName;
}

void ItemToPurchase::SetDescription(std::string productDescription) { // Sets the description of a product
    itemDescription = productDescription;
}

void ItemToPurchase::SetPrice(double productPrice) { // Sets the price of a product
    itemPrice = productPrice;
}

void ItemToPurchase::SetQuantity(int productQuantity) { // Sets the quantity of a product
    itemQuantity = productQuantity;
}

string ItemToPurchase::GetName() const { // Returns the name of a product
    return itemName;
}

string ItemToPurchase::GetDescription() const { // Returns the description of a product
    return itemDescription;
}

double ItemToPurchase::GetPrice() const { // Returns the price of a product
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const { // Returns the quantity of a product
    return itemQuantity;
}

void ItemToPurchase::PrintProductCost() const { // Prints the name, quantity, price, and total price (quantity * price) of a product
    cout << fixed << setprecision(2);
    cout << itemName << " ";
    cout << itemQuantity << " @ $";
    cout << itemPrice << " = ";
    cout << itemPrice * itemQuantity;
}

void ItemToPurchase::PrintProductDescription() const { // Prints the description of a product
    cout << itemDescription << endl;
}