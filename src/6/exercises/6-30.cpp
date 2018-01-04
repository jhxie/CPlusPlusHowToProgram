/**
 * @section DESCRIPTION
 *
 * Reverse Digits.
 *
 * Write a function that takes an integer value and returns the number with its
 * digits reversed. For example, given the number 7631, the function should
 * return 1367.
 */

#include <iostream>

using namespace std;

using ulong = unsigned long;

static ulong ReverseDigits(ulong number)
{
    ulong result {0};

    while (number != 0) {
        result += number % 10;
        result *= 10;
        number /= 10;
    }
    // The last digit fills an extra 0, need to account for this.
    result /= 10;
    return result;
}

int main(void)
{
    ulong number {0U};
    bool initial {true};

    cout << "Press [Ctrl-D] on UNIX or [Ctrl-Z] on Windows to quit.\n";
    do {
        if (initial) {
            initial = false;
        } else {
            cout << "The number in reverse: " << ReverseDigits(number) << endl;
        }
        cout << "Enter number to reverse: ";
    } while (cin >> number);

    cout << endl;

    return 0;
}
