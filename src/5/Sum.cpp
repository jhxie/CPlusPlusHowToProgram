/**
 * 5.5
 * Summing integers with the 'for' statement.
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned int total {0};

    // Total even integers from 2 through 20.
    for (unsigned int number {2}; number <= 20; number += 2) {
        total += number;
    }

    cout << "Sum is " << total << ", based on consecutive addition." << endl;
    cout \
        << "Sum is " << (2 + 20) * ((20 - 2) / 2 + 1) / 2
        << ", based on arithmetic series calculation." << endl;
    return 0;
}
