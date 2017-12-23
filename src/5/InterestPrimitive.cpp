/**
 * 5.6
 * Compound-interest calculations with 'for'.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
    double principal {1000.00}; // Initial amount before interest
    double rate {0.05};         // Interest rate
    double amount {0};

    // Set floating-point number format.
    cout << fixed << setprecision(2);
    cout << "Initial principal: " << principal << endl;
    cout << "    Interest Rate:    " << rate << endl;

    // Display headers.
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    // Calculate amount on deposit for each of ten years.
    for (unsigned int year {1}; year <= 10; ++year) {
        // Calculate amount on deposit at the end of the specified year.
        amount = principal * pow(1.0 + rate, static_cast<double>(year));

        // Display the year and the amount.
        cout << setw(4) << year << setw(20) << amount << endl;
    }
    return 0;
}
