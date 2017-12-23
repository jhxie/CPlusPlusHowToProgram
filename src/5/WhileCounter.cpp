/**
 * 5.1
 * Counter-controlled iteration with the while iteration statement.
 */
#include <iostream>

using namespace std;

int main(void)
{
    unsigned int counter {1}; // Declare and initialize control variable

    while (counter <= 10) { // Loop-continuation condition
        cout << counter++ << " ";
    }
    cout << endl;
    return 0;
}
