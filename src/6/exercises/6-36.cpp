/**
 *
 * @section DESCRIPTION
 *
 * Recursive Exponentiation.
 *
 * Write a recursive function power(base, exponent) that, when invoked, returns
 *
 * baseexponent
 *
 * For example, power(3, 4) = 3 * 3 * 3 * 3. Assume that exponent is an integer
 * greater than or equal to 1. Hint: The recursion step would use the
 * relationship
 *
 * baseexponent = base * baseexponent - 1
 *
 * and the terminating condition occurs when exponent is equal to 1, because
 *
 * base1 = base
 */

#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <iostream>

using boost::multiprecision::checked_cpp_int;

static checked_cpp_int
Power(const checked_cpp_int &base, const checked_cpp_int &exponent)
{
    assert(base >= 0 && exponent > 0);

    if (exponent == 1) {
        return base;
    }
    return base * Power(base, exponent - 1);
}

int main(void)
{
    using namespace std;

    checked_cpp_int base, exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    cout \
        << "Power(" << base << ", " << exponent << ") = "
        << Power(base, exponent) << endl;
    return 0;
}
