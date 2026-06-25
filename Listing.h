#ifndef LISTING_H
#define LISTING_H

#include "Product.h"
#include <string>
using namespace std;

//  Composition: Listing HAS-A Product
class Listing {
private:
    Product* product;
    string sellerName;
    bool available;

public:
    Listing(Product* p, string seller)
        : product(p), sellerName(seller), available(true) {}

    //  Getters
    Product* getProduct() const { return product; }
    string getSeller() const { return sellerName; }
    bool isAvailable() const { return available; }

    //  Mark as sold
    void markSold() { available = false; }

    //  Display summary (for left panel)
    string getSummary() const {
        return product->getName() + " - ₹" + to_string((int)product->getPrice());
    }
};

#endif