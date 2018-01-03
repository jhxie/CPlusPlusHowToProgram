/**
 * 7.17
 * Initializing multidimensional arrays.
 */

#include <array>
#include <cstddef>
#include <iostream>

using namespace std;

static constexpr size_t kRows {2};
static constexpr size_t kColumns {3};

static void Print2DArray(const array<array<int, kColumns>, kRows> &);

int main(void)
{
    array<array<int, kColumns>, kRows> array_1 {
        {{{1, 2, 3}}, {{4, 5, 6}}}
    };
    array<array<int, kColumns>, kRows> array_2 {
        {{{1, 2, 3}}, {{4, 5}}}
    };

    cout << "Values in 'array_1' by row are:" << endl;
    Print2DArray(array_1);

    cout << "Values in 'array_2' by row are:" << endl;
    Print2DArray(array_2);

    return 0;
}

/**
 * Output array with two rows and three columns.
 */
static void Print2DArray(const array<array<int, kColumns>, kRows> &array_2d)
{
    // Loop through rows.
    for (auto const &row : array_2d) {
        // Loop through columns of current row.
        for (auto const &element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
