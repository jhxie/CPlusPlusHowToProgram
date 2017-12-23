/**
 * 5.9
 * do...while iteration statement.
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned int counter {1};

    do {
        cout << counter << " ";
        ++counter;
    } while (++counter <= 10);

    cout << endl;
    return 0;
}
