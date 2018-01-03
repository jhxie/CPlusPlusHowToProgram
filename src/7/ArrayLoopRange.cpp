/**
 * 7.11
 * Using range-based for to multiply an array's elements by 2.
 */
#include "DisplayArray.hpp"

#include <array>
#include <iostream>

using namespace std;

int main(void)
{
    array<int, 5> items {
        {1, 2, 3, 4, 5}
    };

    // Display 'items' before modification.
    cout << "'items' before modification: ";
    DisplayArray(items);

    // Multiply the elements of 'items' by 2.
    for (int &item_reference : items) {
        item_reference *= 2;
    }

    // Display 'items' after modification.
    cout << "'items' after modification: ";
    DisplayArray(items);
    return 0;
}
