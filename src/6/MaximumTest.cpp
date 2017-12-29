/**
 * 6.23
 * Function template 'Maximum' test program.
 */

#include <iostream>
#include "Maximum.hpp"

using namespace std;

int main(void)
{
    // Demonstrate 'Maximum' with int values.
    cout << "Input three integer values: ";
    int int_1, int_2, int_3;
    cin >>  int_1 >> int_2 >> int_3;

    // Invoke int version of 'Maximum'.
    cout << "The maximum integer value is: " << Maximum(int_1, int_2, int_3);

    // Demonstrate 'Maximum' with double values.
    cout << "\n\nInput three double values: ";
    double double_1, double_2, double_3;
    cin >> double_1 >> double_2 >> double_3;

    // Invoke double version of 'Maximum'.
    cout \
        << "THe maximum double value is: "
        << Maximum(double_1, double_2, double_3);

    // Demonstrate 'Maximum' with char values.
    cout << "\n\nInput three characters: ";
    char char_1, char_2, char_3;
    cin >> char_1 >> char_2 >> char_3;

    // Invoke char version of 'Maximum'.
    cout \
        << "The maximum character value is: "
        << Maximum(char_1, char_2, char_3)
        << endl;
    return 0;
}
