#ifndef INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
#define INC_7_21_PREP_LAB_ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase {
    public:
        ItemToPurchase();
        void SetName(std::string productName);
        void SetPrice(double productPrice);
        void SetQuantity(int productQuantity);
        std::string GetName() const;
        double GetPrice() const;
        int GetQuantity() const;

    private:
        std::string itemName;
        double itemPrice;
        int itemQuantity;
};


#endif //INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
