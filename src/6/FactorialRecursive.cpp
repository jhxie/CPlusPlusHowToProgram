/**
 * 6.25
 * Recursive function 'Factorial' demonstration.
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
        cout << setw(2) << counter << "! = " << Factorial(counter) << endl;
    }
    return 0;
}

/**
 * Recursive definition of function 'Factorial'.
 */
static ulong Factorial(const ulong &number)
{
    /*
     * Test for base case: 0! = 1 and 1! = 1.
     */
    if (number <= 1UL) {
        return 1;
    } else {
        return number * Factorial(number - 1UL);
    }
}
