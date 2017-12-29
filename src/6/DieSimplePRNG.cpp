/**
 * 6.8
 * Randomizing the die-rolling program.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    unsigned int seed {0}; // stores the seed entered by the user

    cout << "Enter seed value for the PRNG: ";
    cin >> seed;

    srand(seed); // seed random number generator

    // Loop 10 times.
    for (unsigned int counter {1}; counter <= 10; ++counter) {
        // Pick random number from 1 to 6 and output it.
        cout << setw(10) << (1 + rand() % 6);

        // If 'counter' is divisible by 5, start a new line of output.
        if (counter % 5 == 0) {
            cout << endl;
        }
    }

    return 0;
}
