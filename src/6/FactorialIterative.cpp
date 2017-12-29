/**
 * 6.28
 * Iterative function 'Factorial'.
 */

#include <iomanip>
#include <iostream>

using namespace std;
using ulong = unsigned long;

static ulong Factorial(const ulong &);

int main(void)
{
    // Calculate the factorials of 0 through 10.
    for (ulong counter {0U}; counter <= 10U; ++counter) {
        cout \
            << setw(2) << counter << "! = " << Factorial(counter) << endl;
    }
    return 0;
}

/**
 * Iterative definition of function 'Factorial'.
 */
static ulong Factorial(const ulong &number)
{
    ulong result {1U};

    for (ulong i {number}; i > 1U; --i) {
        result *= i;
    }

    return result;
}
