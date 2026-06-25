#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Product.h"

//  Derived Class
class Electronics : public Product {
private:
    string brand;
    string condition;

public:
    Electronics(string n, double p, string b, string c)
        : Product(n, p, "Electronics"), brand(b), condition(c) {}

    //  Polymorphism (Override)
    string getDetails() const override {
        return "Electronics: " + name +
               "\nBrand: " + brand +
               "\nCondition: " + condition;
    }
};

#endif