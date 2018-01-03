/**
 * 7.15
 * Sorting and searching arrays.
 */

#include "DisplayArray.hpp"

#include <algorithm> // contains 'sort' and 'binary_search'
#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    static constexpr size_t kArraySize {7};
    array<string, kArraySize> colors {
        {"red", "orange", "yellow", "green", "blue", "indigo", "violet"}
    };

    // Output original array.
    cout << "Unsorted Array:" "\n";
    DisplayArray(colors);

    sort(colors.begin(), colors.end()); // sort contents of 'colors'

    // Output sorted array.
    cout << "\n" "Sorted Array:" "\n";
    DisplayArray(colors);

    // Search for 'indigo' in colors.
    bool found {
        binary_search(colors.begin(), colors.end(), "indigo")
    };
    cout \
        << "\n\n" "'indigo' was" << (found ? "" : " not")
        << " found in 'colors'" << endl;

    // Search for 'cyan' in colors.
    found = binary_search(colors.begin(), colors.end(), "cyan");
    cout \
        << "'cyan' was" << (found ? "" : " not")
        << " found in 'colors'" << endl;
    return 0;
}
