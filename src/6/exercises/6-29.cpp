/**
 * @section DESCRIPTION
 *
 * Prime Numbers.
 *
 * An integer is said to be prime if it’s divisible by only 1 and itself. For
 * example, 2, 3, 5 and 7 are prime, but 4, 6, 8 and 9 are not.
 *
 * Write a function that determines whether a number is prime.
 *
 * Use this function in a program that determines and prints all the prime
 * numbers between 2 and 10,000. How many of these numbers do you really have
 * to test before being sure that you’ve found all the primes?
 *
 * Initially, you might think that n/2 is the upper limit for which you must
 * test to see whether a number is prime, but you need only go as high as the
 * square root of n. Why? Rewrite the program, and run it both ways. Estimate
 * the performance improvement.
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

static bool IsPrime(const unsigned int &number)
{
    if (number < 2) {
        return false;
    }

    const unsigned int kDivisorLimit = static_cast<unsigned int>(sqrt(number));

    for (unsigned int divisor {2}; divisor <= kDivisorLimit; ++divisor) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    constexpr int kWidth {15};
    cout \
        << setw(kWidth) << "Prime Number"
        << setw(kWidth) << "[2, 10'000]" << endl;

    for (unsigned candidate {2U}; candidate <= 10'000U; ++candidate) {
        if (IsPrime(candidate)) {
            cout << setw(kWidth) << candidate << endl;
        }
    }

    return 0;
}
