#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"

// CONSTRUCTORS
ShoppingCart::ShoppingCart() { // Default Constructor
    customerName = "none";
    cartDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(std::string userName, std::string currDate) {// Parameterized Constructor
    customerName = userName;
    cartDate = currDate;
}

// FUNCTIONS
void ShoppingCart::AddCart(ItemToPurchase item) { // Adds item to cart
    if (FindInCart(item.GetName()) != -1) {
        std::cout << "Item is already found in the cart. It will not be added." << std::endl;
    }
    else {
        cartList.push_back(item);
    }
}

void ShoppingCart::RemoveCart(std::string itemName) { // Removes item from cart
    if (FindInCart(itemName) == -1) {
        std::cout << "Item not found in cart. It will not be removed." << std::endl;
    }
    else {
        cartList.erase(cartList.begin() + FindInCart(itemName));
    }
}

void ShoppingCart::UpdateQuantity(std::string itemName, int newQty) { // Update quantity of item in cart
    ItemToPurchase item;
    if (FindInCart(itemName) == -1) {
        std::cout << "Item not found in cart. It will not be modified." << std::endl;
    }
    else {
        cartList.at(FindInCart(itemName)).SetQuantity(newQty);
    }
}

std::string ShoppingCart::GetCustomerName() const { // Returns customer name
    return customerName;
}

std::string ShoppingCart::GetCartDate() const { // Returns date of cart creation
    return cartDate;
}

int ShoppingCart::GetCartQuantity() const { // Returns the total amount of items in cart
    ItemToPurchase resultItem;
    unsigned int i;
    int totalQuantity = 0;

    for (i = 0; i < cartList.size(); i++) {
        resultItem = cartList.at(i);
        totalQuantity = totalQuantity + resultItem.GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCartCost() const { // Returns the total cost of cart
    ItemToPurchase resultItem;
    double totalCost = 0;
    unsigned int i;

    for (i = 0; i < cartList.size(); i++) {
        resultItem = cartList.at(i);
        totalCost = totalCost + (resultItem.GetQuantity() * resultItem.GetPrice());
    }
    return totalCost;
}

void ShoppingCart::PrintDescriptions() const { // Prints all item names and descriptions in cart
    ItemToPurchase resultItem;
    unsigned int i;

    std::cout << GetCustomerName() << "'s Shopping Cart - " << GetCartDate() << std::endl << std::endl;

    if (cartList.size() == 0) {
        std::cout << "Shopping cart is empty." << std::endl;
    }
    else {
        std::cout << "Item Descriptions" << std::endl;
        for (i = 0; i < cartList.size(); i++) {
            resultItem = cartList.at(i);
            std::cout << resultItem.GetName() << ": " << resultItem.GetDescription() << std::endl;
        }
    }
}

void ShoppingCart::PrintCartQtyCost() const { // Prints all item names, quantities and prices in cart
    ItemToPurchase resultItem;
    unsigned int i;

    std::cout << GetCustomerName() << "'s Shopping Cart - " << GetCartDate() << std::endl;

    if (cartList.size() == 0) {
        std::cout << "Shopping cart is empty." << std::endl;
    }
    else {
        std::cout << "Number of Items: " << GetCartQuantity() << std::endl << std::endl;
        for (i = 0; i < cartList.size(); i++) {
            resultItem = cartList.at(i);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << resultItem.GetName() << " " << resultItem.GetQuantity() << "@ $" << resultItem.GetPrice() << " = $" << resultItem.GetQuantity() * resultItem.GetPrice() << std::endl;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::endl << "Total: $" << GetCartCost() << std::endl;
    }
}

int ShoppingCart::FindInCart(std::string itemName) { // Finds position of item in cart. Returns -1 if item not found.
    ItemToPurchase item;
    unsigned int i;

    int position = -1;
    for (i = 0; i < cartList.size(); i++) {
        item = cartList.at(i);
        if (itemName == item.GetName()) {
            position = i;
        }
    }
    return position;
}
