#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

//  Abstract Base Class
class Product {
protected:
    string name;
    double price;
    string category;

public:
    Product(string n, double p, string c)
        : name(n), price(p), category(c) {}

    //  Pure Virtual Function (Polymorphism)
    virtual string getDetails() const = 0;

    //  Getters (Encapsulation)
    string getName() const { return name; }
    double getPrice() const { return price; }
    string getCategory() const { return category; }

    //  Operator Overloading
    bool operator<(const Product& other) {
        return this->price < other.price;
    }

    bool operator>(const Product& other) {
        return this->price > other.price;
    }

    virtual ~Product() {}
};

#endif