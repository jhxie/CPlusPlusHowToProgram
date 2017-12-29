/**
 * 6.26
 * Recursive function 'Fibonacci' demonstration.
 */

#include <iostream>

using namespace std;

using ulong = unsigned long;

static ulong Fibonacci(const ulong &);

int main(void)
{
    // Calculate the fibonacci values of 0 through 10.
    for (ulong counter {0U}; counter <= 10U; ++counter) {
        cout \
            << "Fibonacci(" << counter << ") = " << Fibonacci(counter) << endl;
    }

    // Display higher fibonacci values.
    cout << "\n" "Fibonacci(20) = " << Fibonacci(20U) << endl;
    cout << "Fibonacci(30) = " << Fibonacci(30U) << endl;
    cout << "Fibonacci(35) = " << Fibonacci(35U) << endl;
    return 0;
}

/**
 * Recursive definition of function 'Fibonacci'.
 */
static ulong Fibonacci(const ulong &number)
{
    switch (number) {
    case 0:
    case 1:
        return number;
    default:
        return Fibonacci(number - 1U) + Fibonacci(number - 2U);
    }
}
