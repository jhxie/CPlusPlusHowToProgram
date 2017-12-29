/**
 * 6.10
 * Using a C++ 11 random-number generation engine and distribution to roll a
 * six-sided die.
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main(void)
{
    /*
     * From 6.9 (Chapter 6 Section 9) of
     * C++ How to Program, 10th Edition
     * "
     * Its constructor argument seeds the random-number generation engine with
     * the current time. If you don’t pass a value to the constructor, the
     * default seed will be used and the program will produce the same sequence
     * of numbers each time it executes - this is useful for testing purposes.
     * "
     */
    default_random_engine engine {static_cast<unsigned int>(time(0))};
    uniform_int_distribution<unsigned int> random_int {1, 6};

    // Loop 10 times.
    for (unsigned int counter {1}; counter <= 10; ++counter) {
        // Pick random number from 1 to 6 and output it.
        cout << setw(10) << random_int(engine);

        // If 'counter' is divisible by 5, start a new line of output.
        if (counter % 5 == 0) {
            cout << endl;
        }
    }

    return 0;
}
