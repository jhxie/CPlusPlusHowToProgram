/**
 * 5.6
 * Compound-interest calculations with class 'DollarAmount' and integers.
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "DollarAmount.hpp"

using namespace std;

int main(void)
{
    DollarAmount balance_1 {12345}; // $123.45
    DollarAmount balance_2 {1576}; // $15.76

    cout \
        << "After adding 'balance_2' (" << balance_2.ToString()
        << ") into 'balance_1' (" << balance_1.ToString()
        << "), 'balance_1' = ";
    balance_1.Add(balance_2); // Modifies object 'balance_1'
    cout << balance_1.ToString() << "\n";

    cout \
        << "After subtracting 'balance_2' (" << balance_2.ToString()
        << ") from 'balance_1'" << balance_1.ToString()
        << "), 'balance_1' = ";
    balance_1.Subtract(balance_2); // Modifies object 'balance_1'
    cout << balance_1.ToString() << "\n";

    cout \
        << "After subtracting 'balance_1' (" << balance_1.ToString()
        << ") from 'balance_2' (" << balance_2.ToString()
        << "), 'balance_2' = ";
    balance_2.Subtract(balance_1); // Modifies object 'balance_2'
    cout << balance_2.ToString() << "\n\n";

    cout \
        << "Enter integer interest rate and divisor. For example:\n"
        << "for     2%, enter:    2 100\n"
        << "for   2.3%, enter:   23 1000\n"
        << "for  2.37%, enter:  237 10000\n"
        << "for 2.375%, enter: 2375 100000\n";

    int rate; // whole number interest rate
    int divisor; // divisor for rate

    cin >> rate >> divisor;

    DollarAmount balance {100000}; // initial principal amount in pennies

    cout << "\nInitial balance: " << balance.ToString() << endl;

    // Display headers
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    for (unsigned int year {1}; year <= 10; ++year) {
        // Increase balance by rate % (i.e., rate / divisor).
        balance.AddInterest(rate, divisor);

        // Display the year and the amount
        cout << setw(4) << year << setw(20) << balance.ToString() << endl;
    }

    return 0;
}
