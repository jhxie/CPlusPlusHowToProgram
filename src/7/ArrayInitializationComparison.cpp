/**
 * 7.10
 * Static array initialization and automatic array initialization.
 */

#include <array>
#include <cstddef>
#include <iostream>

using namespace std;

static void InitializeStaticArray();
static void InitializeAutomaticArray();

static constexpr size_t kArraySize{3};

int main(void)
{
    cout << "First call to each function:\n";
    InitializeStaticArray();
    InitializeAutomaticArray();

    cout << "\n\nSecond call to each function:\n";
    InitializeStaticArray();
    InitializeAutomaticArray();

    cout <<endl;
    return 0;
}

/**
 * Function to demonstrate a static local array.
 */
static void InitializeStaticArray()
{
    // Initializes elements to 0 first time function is called.
    static array<int, kArraySize> array_static;

    cout << "\nValues on entering 'InitializeStaticArray':\n";

    // Output contents of 'array_static'.
    for (size_t i {0}; i < array_static.size(); ++i) {
        cout << "array_static[" << i << "] = " << array_static[i] << " ";
    }

    cout << "\nValues on exiting 'InitializeStaticArray':\n";

    // Modify and output contents of 'array_static'.
    for (size_t j {0}; j < array_static.size(); ++j) {
        cout \
            << "array_static[" << j << "] = "
            << (array_static[j] += 5) << "  ";
    }
}

/**
 * Function to demonstrate an automatic local array.
 */
static void InitializeAutomaticArray()
{
    // Initialize elements each time function is called.
    array<int, kArraySize> array_automatic {
        {1, 2, 3}
    };

    cout << "\n\nValues on entering 'InitializeAutomaticArray':\n";

    // Output contents of 'array_automatic'.
    for (size_t i {0}; i < array_automatic.size(); ++i) {
        cout << "array_automatic[" << i << "] = " << array_automatic[i] << " ";
    }

    cout << "\nValues on exiting 'InitializeAutomaticArray':\n";

    // Modify and output contents of 'array_automatic'.
    for (size_t j {0}; j < array_automatic.size(); ++j) {
        cout \
            << "array_automatic[" << j << "] = "
            << (array_automatic[j] += 5) << "  ";
    }
}
