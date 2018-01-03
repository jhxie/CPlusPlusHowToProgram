/**
 * 7.4
 * Initializing an array in a declaration.
 */

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    static constexpr size_t kWidth {10};
    array<int, 5>  number_array {
        {32, 27, 64, 18, 95}
    }; // list initializer

    cout << "Element" << setw(kWidth) << "Value" << endl;

    // Output each array element's value.
    for (size_t i {0}; i < number_array.size(); ++i) {
        cout << setw(7) << i << setw(kWidth) << number_array[i] << endl;
    }
    return 0;
}
