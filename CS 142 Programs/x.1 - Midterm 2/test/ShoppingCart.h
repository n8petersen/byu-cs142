#ifndef INC_7_22_MAIN_LAB_SHOPPINGCART_H
#define INC_7_22_MAIN_LAB_SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(std::string userName, std::string currDate);

    void AddCart(ItemToPurchase item);
    void RemoveCart();
    void UpdateQuantity();

    int GetCartQuantity();
    double GetCartCost();
    std::string GetCustomerName();
    std::string GetCartDate();

    void PrintDescriptions();
    void PrintCartQtyCost();

private:
    std::string customerName;
    std::string cartDate;
    std::vector<ItemToPurchase> cartList;
};


#endif //INC_7_22_MAIN_LAB_SHOPPINGCART_H
