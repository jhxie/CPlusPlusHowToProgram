/**
 * 6.3
 * Maximum function with a function prototype.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int maximum(int x, int y, int z); // function prototype

int main(void)
{
#ifdef PRINT_DEBUG_INFO
#endif
    cout << "Enter three integer values: ";
    int integer_1, integer_2, integer_3;
    cin >> integer_1 >> integer_2 >> integer_3;

    // Invoke maximum.
    cout \
        << "The maximum integer value is: "
        << maximum(integer_1, integer_2, integer_3) << endl;

    return 0;
}

/**
 * Returns the largest of three integers.
 */
int maximum(int x, int y, int z)
{
    int maximum_value {x}; // assume 'x' is the largest to start

    // Determine whether 'y' is greater than 'maximum_value'
    if (y > maximum_value) {
        maximum_value = y; // make 'y' the new 'maximum_value'
    }

    // Determine whether 'z' is greater than 'maximum_value'
    if (z > maximum_value) {
        maximum_value = z; // make 'z' the new 'maximum_value'
    }

    return maximum_value;
}
