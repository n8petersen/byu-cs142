#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

void ItemToPurchase::SetName(std::string productName) {
    itemName = productName;
}

void ItemToPurchase::SetPrice(double productPrice) {
    itemPrice = productPrice;
}

void ItemToPurchase::SetQuantity(int productQuantity) {
    itemQuantity = productQuantity;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

double ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}