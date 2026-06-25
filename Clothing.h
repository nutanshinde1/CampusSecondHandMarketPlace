#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

//  Derived Class
class Clothing : public Product {
private:
    string size;
    string brand;

public:
    Clothing(string n, double p, string s, string b)
        : Product(n, p, "Clothing"), size(s), brand(b) {}

    //  Polymorphism (Override)
    string getDetails() const override {
        return "Clothing: " + name +
               "\nSize: " + size +
               "\nBrand: " + brand;
    }
};

#endif