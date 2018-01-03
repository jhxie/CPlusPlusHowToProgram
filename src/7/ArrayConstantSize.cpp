/**
 * 7.5
 * Set array 'even_numbers' to the even integers from 2 to 10.
 */

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    // Constant variable can be used to specify array size.
    static constexpr size_t kArraySize {5}; // must initialize in declaration
    array<int, kArraySize> even_numbers;

    for (size_t i {0}; i < even_numbers.size(); ++i) {
        even_numbers[i] = 2 + 2 * static_cast<int>(i);
    }

    static constexpr int kWidth {10};
    cout << "Element" << setw(kWidth) << "Value" << endl;

    // Output contents of array 'even_numbers' in tabular format.
    for (size_t j {0}; j < even_numbers.size(); ++j) {
        cout << setw(7) << j << setw(kWidth) << even_numbers[j] << endl;
    }
    return 0;
}
