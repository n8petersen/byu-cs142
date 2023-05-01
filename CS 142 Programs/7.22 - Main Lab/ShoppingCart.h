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
    void RemoveCart(std::string itemName);
    void UpdateQuantity(std::string itemName, int newQty);

    int GetCartQuantity() const;
    double GetCartCost() const;
    std::string GetCustomerName() const;
    std::string GetCartDate() const;

    void PrintDescriptions() const;
    void PrintCartQtyCost() const;
private:
    std::string customerName;
    std::string cartDate;
    std::vector<ItemToPurchase> cartList;

    int FindInCart(std::string itemName);

};


#endif //INC_7_22_MAIN_LAB_SHOPPINGCART_H
