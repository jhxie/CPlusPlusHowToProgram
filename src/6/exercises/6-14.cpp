/**
 * @section DESCRIPTION
 *
 * Rounding Numbers.
 *
 * Function floor can be used to round a number to a specific decimal place.
 * The statement
 *
 *
 * y = floor(x * 10 + 0.5) / 10;
 * rounds x to the tenths position (the first position to the right of the
 * decimal point). The statement
 *
 *
 * y = floor(x * 100 + 0.5) / 100;
 * rounds x to the hundredths position (the second position to the right of the
 * decimal point). Write a program that defines four functions to round a
 * number x in various ways:
 *
 * roundToInteger(number)
 *
 * roundToTenths(number)
 *
 * roundToHundredths(number)
 *
 * roundToThousandths(number)
 *
 * For each value read, your program should print the original value, the
 * number rounded to the nearest integer, the number rounded to the nearest
 * tenth, the number rounded to the nearest hundredth and the number rounded to
 * the nearest thousandth.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

static inline double RoundToInteger(const double &number);
static inline double RoundToTenths(const double &number);
static inline double RoundToHundredths(const double &number);
static inline double RoundToThousandths(const double &number);

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

    constexpr int kWidth {15};

    if (number_list.size() != 0U) {
        cout << fixed << setprecision(4) << endl;
        cout \
            << setw(kWidth) << "Number"
            << setw(kWidth) << "Integer"
            << setw(kWidth) << "Tenths"
            << setw(kWidth) << "Hundredths"
            << setw(kWidth) << "Thousandths" << endl;

        for (auto &i : number_list) {
            cout \
                << setw(kWidth) << i
                << setw(kWidth) << RoundToInteger(i)
                << setw(kWidth) << RoundToTenths(i)
                << setw(kWidth) << RoundToHundredths(i)
                << setw(kWidth) << RoundToThousandths(i) << endl;
        }
    }

    cout << endl;
    return 0;
}

static inline double RoundToInteger(const double &number)
{
    return floor(number + 0.5);
}

static inline double RoundToTenths(const double &number)
{
    return floor(number * 10 + 0.5) / 10;
}

static inline double RoundToHundredths(const double &number)
{
    return floor(number * 100 + 0.5) / 100;
}

static inline double RoundToThousandths(const double &number)
{
    return floor(number * 1000 + 0.5) / 1000;
}
