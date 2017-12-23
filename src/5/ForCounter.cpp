/**
 * 5.2
 * Counter-controlled iteration with the for iteration statement.
 */

#include <iostream>

using namespace std;

int main(void)
{
    // 'for' statement header includes initialization, loop-continuation
    // and increment.
    for (unsigned int counter {1}; counter <= 10; ++counter) {
        cout << counter << " ";
    }
    cout << endl;
    return 0;
}
