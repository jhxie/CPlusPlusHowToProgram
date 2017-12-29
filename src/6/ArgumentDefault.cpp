/**
 * 6.18
 * Using default arguments.
 */

#include <iostream>

using namespace std;

using uint = unsigned int;

// Function prototype that specifies default arguments.
static uint BoxVolume(uint length = 1, uint width = 1, uint height = 1);

int main(void)
{
    // No arguments -- use default values for all dimensions.
    cout << "The default box volume is: " << BoxVolume();

    // Specify 'length'; default 'width' and 'height'.
    cout \
        << "\n\nThe volume of a box with length 10,\n"
        << "width 1 and height 1 is: " << BoxVolume(10);

    // Specify 'length' and 'width'; default 'height'.
    cout \
        << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 1 is: " << BoxVolume(10, 5);

    // Specify all arguments.
    cout \
        << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 2 is: " << BoxVolume(10, 5, 2) << endl;
    return 0;
}

/**
 * Function 'BoxVolume' calculates the volume of a box.
 */
static uint BoxVolume(uint length, uint width, uint height)
{
    return length * width * height;
}
