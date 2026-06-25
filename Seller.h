#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include <vector>

// 🔷 Derived Class
class Seller : public User {
private:
    vector<string> itemsSold;

public:
    Seller(string n) : User(n) {}

    // 🔹 Override
    string getRole() const override {
        return "Seller";
    }

    // 🔹 Add sold item
    void addSoldItem(string itemName) {
        itemsSold.push_back(itemName);
    }

    // 🔹 Get sold items
    vector<string> getSoldItems() const {
        return itemsSold;
    }
};

#endif