/**
 * 6.15
 * Unary scope resolution operator; used to access global namespace.
 */

#include <iostream>

using namespace std;

static int number {7}; // global variable

int main(void)
{
    double number {10.5}; // local variable shadows the global variable

    // Display values of local and global variables.
    cout \
        << "Local double value of 'number' = " << number
        << "\nGlobal int value of 'number' = " << ::number << endl;

    return 0;
}
