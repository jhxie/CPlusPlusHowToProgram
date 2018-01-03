/**
 * 7.3
 * Initializing an array's elements to zeroes and printing the array.
 */

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    array<int, 5> number_array; // an array of 5 'int' values

    // Initialize elements of array to 0.
    for (size_t i {0}; i < number_array.size(); ++i) {
        number_array[i] = 0; // set element at location i to 0
    }

    constexpr int kWidth {10};
    cout << "Element" << setw(kWidth) << "Value" << endl;

    // Output each array element's value.
    for (size_t j {0}; j < number_array.size(); ++j) {
        cout << setw(7) << j << setw(kWidth) << number_array[j] << endl;
    }

    return 0;
}
