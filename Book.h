#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

//  Derived Class
class Book : public Product {
private:
    string author;
    string edition;

public:
    Book(string n, double p, string a, string e)
        : Product(n, p, "Book"), author(a), edition(e) {}

    //  Polymorphism (Override)
    string getDetails() const override {
        return "Book: " + name +
               "\nAuthor: " + author +
               "\nEdition: " + edition;
    }
};

#endif