/**
 * 5.8
 * 'DollarAmount' class stores dollar amounts as a whole number of pennies.
 */

#pragma once

#include <string>
#include <cmath>

class DollarAmount final
{
public:
    // Initialize amount from an 'int64_t' value
    explicit DollarAmount(int64_t value) : amount_ {value}
    {
    }

    // Add right's amount to this object's amount
    void Add(DollarAmount right)
    {
        amount_ += right.amount_;
    }

    // Subtract right's amount from this object's amount
    void Subtract(DollarAmount right)
    {
        amount_ -= right.amount_;
    }

    // Use integer arithmetic to calculate interest amount,
    // then calls add with the interest amount
    void AddInterest(int rate, int divisor)
    {
        // Create 'DollarAmount' representing the interest
        DollarAmount interest {
            // Perform half-up rounding
            (amount_ * rate + divisor / 2) / divisor
        };

        Add(interest);
    }

    std::string ToString() const
    {
        using std::string;
        string dollars { std::to_string(amount_ / 100) };
        string cents { std::to_string(std::abs(amount_ % 100)) };
        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    }
private:
    int64_t amount_ {0}; // Dollar amount in pennies
};
