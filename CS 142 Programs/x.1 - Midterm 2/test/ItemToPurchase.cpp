#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

// Default Constructor
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

// Parameterized Constructor
ItemToPurchase::ItemToPurchase(string productName, string productDescription, double productPrice, int productQuantity) {
    itemName = productName;
    itemDescription = productDescription;
    itemPrice = productPrice;
    itemQuantity = productQuantity;
}

// Sets the name of a product
void ItemToPurchase::SetName(std::string productName) {
    itemName = productName;
}

// Sets the description of a product
void ItemToPurchase::SetDescription(std::string productDescription) {
    itemDescription = productDescription;
}

// Sets the price of a product
void ItemToPurchase::SetPrice(double productPrice) {
    itemPrice = productPrice;
}

// Sets the quantity of a product
void ItemToPurchase::SetQuantity(int productQuantity) {
    itemQuantity = productQuantity;
}


// Gets the name of a product
string ItemToPurchase::GetName() const {
    return itemName;
}

// Gets the description of a product
string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

// Gets the price of a product
double ItemToPurchase::GetPrice() const {
    return itemPrice;
}

// Gets the quantity of a product
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}


// Prints the name, quantity, price, and total price (quantity * price) of a product
void ItemToPurchase::PrintProductCost() {
    cout << fixed << setprecision(2);
    cout << itemName << " ";
    cout << itemQuantity << " @ $";
    cout << itemPrice << " = ";
    cout << itemPrice * itemQuantity;
}

// Prints the description of a product
void ItemToPurchase::PrintProductDescription() {
    cout << itemDescription << endl;
}