/**
 * @section DESCRIPTION
 *
 * Parking Charges.
 *
 * A parking garage charges a $20.00 minimum fee to park for up to three hours.
 * The garage charges an additional $5.00 per hour for each hour or part
 * thereof in excess of three hours. The maximum charge for any given 24-hour
 * period is $50.00. Assume that no car parks for longer than 24 hours at a
 * time. Write a program that calculates and prints the parking charges for
 * each of three customers who parked their cars in this garage yesterday. You
 * should enter the hours parked for each customer.
 *
 * Your program should print the results in a neat tabular format and should
 * calculate and print the total of yesterday’s receipts.
 * The program should use the function calculateCharges to determine the charge
 * for each customer. Your outputs should appear in the following format:
 *
 * Car      Hours        Charge
 * 1          1.5         20.00
 * 2          4.0         25.00
 * 3         24.0         50.00
 * TOTAL     29.5         95.50
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

static double CalculateCharges(const double &hour);

int main(void)
{
    constexpr int kWidthLeft {5}, kWidthMiddle {10}, kWidthRight {15};
    double current_hour {};
    double total_hours {}, current_charge {}, total_charges {};
    vector<double> parking_hours;

    for (int i = 1; i <= 3; ++i) {
        cout << "Enter parking hour for Car #" << i << ": ";
        if (cin >> current_hour) {
            parking_hours.push_back(current_hour);
            total_hours += current_hour;
        }
    }

    if (parking_hours.size() != 0U) {
        cout << fixed << setprecision(2);
        cout \
            << setw(kWidthLeft) << left << "Car" << right
            << setw(kWidthMiddle) << "Hours"
            << setw(kWidthRight) << "Charge" << endl;
    }

    for (decltype(parking_hours.size()) i = 0; i < parking_hours.size(); ++i) {
        current_charge = CalculateCharges(parking_hours[i]);
        total_charges += current_charge;
        cout \
            << setw(kWidthLeft) << left << i + 1 << right
            << setw(kWidthMiddle) << parking_hours[i]
            << setw(kWidthRight) <<  current_charge << endl;
    }

    if (parking_hours.size() != 0) {
        cout \
            << setw(kWidthLeft) << left << "TOTAL" << right
            << setw(kWidthMiddle) << total_hours
            << setw(kWidthRight) << total_charges << endl;
    }

    return 0;
}

static double CalculateCharges(const double &hour)
{
    double charge {20};

    if (hour <= 3) {
        return charge;
    } else {
        charge += (hour - 3) * 5;

        // The maximum charge for any given 24-hour period is $50.00.
        // Assume that no car parks for longer than 24 hours at a time.
        return charge > 50 ? 50 : charge;
    }
}
