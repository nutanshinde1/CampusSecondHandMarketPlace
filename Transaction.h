#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

// 🔷 Transaction Class
class Transaction {
private:
    string buyerName;
    string sellerName;
    string productName;
    double price;
    string date;

public:
    Transaction(string b, string s, string p, double pr, string d)
        : buyerName(b), sellerName(s), productName(p), price(pr), date(d) {}

    // 🔹 Get Details
    string getDetails() const {
        return "Buyer: " + buyerName +
               "\nSeller: " + sellerName +
               "\nProduct: " + productName +
               "\nPrice: ₹" + to_string((int)price) +
               "\nDate: " + date;
    }
};

#endif