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
    // Constructor initializes data member name with parameter 'account_name'
    // explicit Account(std::string account_name) : name_{account_name} {
    // }
    Account(std::string account_name, int initial_balance)
        : name_{account_name} {

        // Validate that the 'initial_balance' is greater than 0; if not,
        // data member balance keeps its default initial value of 0.
        if (initial_balance > 0) {
            balance_ = initial_balance;
        }
    }

    // Function that deposits only a valid amount to the balance.
    void Deposit(int deposit_amount) {
        if (deposit_amount > 0) {
            balance_ += deposit_amount;
        }
    }

    // Member function that sets the account name in the object.
    void SetName(std::string account_name) {
        name_ = account_name;
    }

    int GetBalance() const {
        return balance_;
    }

    // Member function that retrieves the account name from the object.
    std::string GetName() const {
        return name_;
    }

private:
    std::string name_;
    int balance_{0}; // Data member with default initial value
};
