/**
 * 6.16
 * Inline function that calculates the volume of a cube.
 */

#include <iostream>

using namespace std;

/**
 * Definition of inline function 'cube'.
 *
 * Definition of function appears before function is called, so a function
 * prototype is not required; first line of function definition acts as the
 * prototype.
 */
inline double cube(const double side)
{
    return side * side * side;
}

int main(void)
{
    double side_value; // stores value entered by user

    cout << "Enter the side length of your cube: ";
    cin >> side_value;

    // Calculate cube of 'side_value' and display result.
    cout \
        << "Volume of cube with side " << side_value << " is "
        << cube(side_value) << endl;
    return 0;
}
