/**
 * @section DESCRIPTION
 *
 * Rounding Numbers.
 *
 * An application of function floor is rounding a value to the nearest integer.
 * The statement
 *
 * y = floor(x + 0.5);
 *
 * rounds the number x to the nearest integer and assigns the result to y.
 * Write a program that reads several numbers and uses the preceding statement
 * to round each of these numbers to the nearest integer. For each number
 * processed, print both the original number and the rounded number.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

static inline double Round(const double &number);

int main(void)
{
    double number {};
    list<double> number_list;

    cout \
        << "Enter numbers you would like to round;\n"
        << "press [Ctrl+D] on UNIX or [Ctrl+Z] on Windows to quit." << endl;

    for (;;) {
        cout << "Enter number: ";
        if (cin >> number) {
            number_list.push_back(number);
        } else {
            break;
        }
    }

    constexpr int kWidth {20};

    if (number_list.size() != 0U) {
        cout << fixed << setprecision(2) << endl;
        cout \
            << setw(kWidth) << "Number"
            << setw(kWidth) << "Rounded Number" << endl;

        for (auto &i : number_list) {
            cout << setw(kWidth) << i << setw(kWidth) << Round(i) << endl;
        }
    }

    cout << endl;
    return 0;
}
static inline double Round(const double &number)
{
    return floor(number + 0.5);
}
