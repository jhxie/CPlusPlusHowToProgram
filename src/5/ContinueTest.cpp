/**
 * 5.14
 * 'continue' statement terminating an iteration of a 'for' statement.
 */

#include <iostream>

using namespace std;

int main(void)
{
    // Loop 10 times.
    for (unsigned int counter {1}; counter <= 10; ++counter) {
        if (counter == 5) {
            continue; // skip remaining code in loop body if 'counter' is 5
        }
        cout << counter << " ";
    }

    cout << "\nUsed continue to skip printing 5" << endl;
    return 0;
}
