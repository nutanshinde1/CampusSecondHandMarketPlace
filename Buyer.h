#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include "Listing.h"
#include <vector>

//  Derived Class
class Buyer : public User {
private:
    vector<Listing*> wishlist;

public:
    Buyer(string n) : User(n) {}

    //  Override
    string getRole() const override {
        return "Buyer";
    }

    //  Add to Wishlist
    void addToWishlist(Listing* item) {
        wishlist.push_back(item);
    }

    //  Get Wishlist
    vector<Listing*> getWishlist() const {
        return wishlist;
    }
};

#endif