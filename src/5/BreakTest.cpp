/**
 * 5.13
 * 'break' statement exiting a 'for' statement.
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned int counter; // control variable also used after loop

    for (counter = 1; counter <= 10; ++counter) {
        if (counter == 5) {
            break; // terminates loop if 'counter' is 5
        }
        cout << counter << " ";
    }

    cout << "\nBroke out of loop at 'counter' = " << counter << endl;
    return 0;
}
