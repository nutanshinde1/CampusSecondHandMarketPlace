#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Abstract Base Class
class User {
protected:
    string name;

public:
    User(string n) : name(n) {}

    string getName() const { return name; }

    //  Pure Virtual Function
    virtual string getRole() const = 0;

    virtual ~User() {}
};

#endif