/**
 * 6.6
 * Shifted, scaled integers produced by 1 + rand() % 6.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    // Loop 20 times.
    for (unsigned int counter {1}; counter <= 20; ++counter) {
        // Pick random number from 1 to 6 and output it.
        cout << setw(10) << (1 + rand() % 6);

        // If 'counter' is divisible by 5, start a new line of output.
        if (counter % 5 == 0) {
            cout << endl;
        }
    }

    return 0;
}
