/**
 * 7.7
 * Bar chart printing program.
 */

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    static constexpr size_t kArraySize {11};
    array<unsigned int, kArraySize> grade_frequency {
        {0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1}
    };

    cout << "Grade Distribution:" << endl;

    // For each element of array, output a bar of the chart.
    for (size_t i {0}; i < grade_frequency.size(); ++i) {
        // Output bar labels (0-9, ... 90 - 99, 100).
        if (i == 0) {
            cout << "  0-9: ";
        } else if (i == 10) {
            cout << "  100: ";
        } else {
            cout << i * 10 << "-" << i * 10 + 9 << ": ";
        }

        for (decltype(grade_frequency)::value_type stars {0};
             stars < grade_frequency[i];
             ++stars) {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}
