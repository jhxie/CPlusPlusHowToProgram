/**
 * 7.6
 * Compute the sum of the elements of an array.
 */

#include <array>
#include <cstddef>
#include <iostream>

using namespace std;

int main(void)
{
    static constexpr size_t kArraySize {4};
    array<int, kArraySize> numbers {
        {10, 20, 30, 40}
    };
    long total {0};

    // Sum contents of array 'numbers'.
    for (size_t i {0}; i < numbers.size(); ++i) {
        total += numbers[i];
    }

    cout << "Total of array elements: " << total << endl;
    return 0;
}
