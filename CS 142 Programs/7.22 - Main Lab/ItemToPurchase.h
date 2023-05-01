#ifndef INC_7_22_MAIN_LAB_ITEMTOPURCHASE_H
#define INC_7_22_MAIN_LAB_ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(std::string productName, std::string productDescription, double productPrice, int productQuantity);

    void SetName(std::string productName);
    void SetDescription(std::string productDescription);
    void SetPrice(double productPrice);
    void SetQuantity(int productQuantity);

    std::string GetName() const;
    std::string GetDescription() const;
    double GetPrice() const;
    int GetQuantity() const;

    void PrintProductCost() const;
    void PrintProductDescription() const;

private:
    std::string itemName;
    std::string itemDescription;
    double itemPrice;
    int itemQuantity;
};


#endif //INC_7_22_MAIN_LAB_ITEMTOPURCHASE_H
