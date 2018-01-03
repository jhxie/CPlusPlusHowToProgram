/**
 * 7.9
 * Poll analysis program.
 */

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    // Define array sizes.
    static constexpr size_t kResponseSize {20};
    // The response rating is in range [1, 5], 0 is not used.
    static constexpr size_t kFrequencySize {6};

    // Place survey responses.
    static constexpr array<unsigned int, kResponseSize> responses {
        {1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5}
    };
    array<unsigned int, kFrequencySize> frequency {};

    // For each answer, select 'responses' element and use that value as
    // 'frequency' subscript to determine element to increment.
    for (size_t i {0}; i < responses.size(); ++i) {
        ++frequency[responses[i]];
    }

    static constexpr int kWidth {12};

    cout << "Rating" << setw(kWidth) << "Frequency" << endl;

    // Output each array element's value.
    for (size_t rating {1}; rating < frequency.size(); ++rating) {
        cout << setw(6) << rating << setw(kWidth) << frequency[rating] << endl;
    }
    return 0;
}
