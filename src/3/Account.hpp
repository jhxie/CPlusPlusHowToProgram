/**
 * Account class that contains a name data member and member functions to set
 * and get its value.
 */
#pragma once

#include <string>

class Account final {
public:
    // Compiler would not provide default constructor for class that has a
    // custom defined constructor.
    //
    // Constructor initializes data member name with parameter 'accountName'
    // explicit Account(std::string accountName) : name{accountName} {
    // }
    Account(std::string accountName, int initialBalance) : name{accountName} {

        // Validate that the 'initialBalance' is greater than 0; if not,
        // data member balance keeps its default initial value of 0.
        if (initialBalance > 0) {
            balance = initialBalance;
        }
    }

    // Function that deposits only a valid amount to the balance.
    void deposit(int depositAmount) {
        if (depositAmount > 0) {
            balance += depositAmount;
        }
    }

    // Member function that sets the account name in the object.
    void setName(std::string accountName) {
        name = accountName;
    }

    int getBalance() const {
        return balance;
    }

    // Member function that retrieves the account name from the object.
    std::string getName() const {
        return name;
    }

private:
    std::string name;
    int balance{0}; // Data member with default initial value
};
