#include <iostream>
#include <algorithm>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

// CONSTRUCTORS
// Default Constructor
ShoppingCart::ShoppingCart() {
    customerName = "none";
    cartDate = "January 1, 2016";
}
// Parameterized Constructor
ShoppingCart::ShoppingCart(std::string userName, std::string currDate) {
    customerName = userName;
    cartDate = currDate;
}

// FUNCTIONS
void ShoppingCart::AddCart(ItemToPurchase item) {
    std::string key = item.GetName();
    if (std::find(cartList.begin(), cartList.end(), key) != cartList.end()) {
        std::cout << "Item found";
    }
    else {
        std::cout << "Item not found";
        cartList.push_back(item);
    }

    std::cout << cartList.size() << std::endl;
}

void ShoppingCart::RemoveCart() {
    // TODO: Remove an item object from the cart. Accepts an item name as a parameter.
    // TODO: If item name cannot be found, prints this message: "Item not found in cart. It will not be removed."
}

void ShoppingCart::UpdateQuantity() {
    // TODO: Update the quantity of an item object in the cart
    // TODO: If item name cannot be found, prints this message: "Item not found in cart. It will not be modified." If the quantity is set to 0, still leave the item in the cart, but treat it as a 0 in all counts, etc.
}

std::string ShoppingCart::GetCustomerName() {
    return customerName;
}

std::string ShoppingCart::GetCartDate() { // Get date of cart creation
    return cartDate;
}

int ShoppingCart::GetCartQuantity() {
    // TODO: Add loop to get the total amount of items in cart
    return 0;
}

double ShoppingCart::GetCartCost() {
    // TODO: Add loop to get the total cart cost
    return 0;
}

void ShoppingCart::PrintDescriptions() {
    ItemToPurchase resultItem;
    if (cartList.size() == 0) {
        std::cout << "Shopping cart is empty." << std::endl;
    }
    else {
        std::cout << customerName << "'s Shopping Cart - " << cartDate << std::endl << std::endl;
        std::cout << "Item Descriptions" << std::endl;
        for (int i = 0; i < cartList.size(); i++) {
            resultItem = cartList.at(i);
            std::cout << resultItem.GetName() << ": " << resultItem.GetDescription() << std::endl;
        }
    }
}

void ShoppingCart::PrintCartQtyCost() {
    if (cartList.size() == 0) {
        std::cout << "Shopping cart is empty." << std::endl;
    }
    else {
        std::cout << customerName << "'s Shopping Cart - " << cartDate << std::endl;
        std::cout << "Number of Items: " << GetCartQuantity() << std::endl << std::endl;
        for (int i = 0; i < cartList.size(); i++) {
            // TODO: Add loop to list item quantities and prices
        }
        std::cout << std::endl << "Total: " << GetCartCost() << std::endl;
    }
}
