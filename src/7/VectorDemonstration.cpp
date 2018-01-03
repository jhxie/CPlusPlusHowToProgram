/**
 * 7.21
 * Demonstrating C++ standard library class template 'vector'.
 */

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

static void OutputVector(const vector<int> &);
static void InputVector(vector<int> &);

int main(void)
{
    vector<int> integers_1(7);
    vector<int> integers_2(10);

    // Print 'integers_1' size and contents.
    cout \
        << "Size of vector 'integers_1' is " << integers_1.size() << "\n"
        << "vector after initialization: ";
    OutputVector(integers_1);

    // Print 'integers_2' size and contents.
    cout \
        << "\n" "Size of vector 'integers_2' is " << integers_2.size() << "\n"
        << "vector after initialization: ";
    OutputVector(integers_2);

    // Input and print 'integers_1' and 'integers_2'.
    cout << "\n" "Enter 17 integers:" << endl;
    InputVector(integers_1);
    InputVector(integers_2);

    cout << "\n" "After input, the vectors contain:" "\n" << "'integers_1': ";
    OutputVector(integers_1);
    cout << "'integers_2': ";
    OutputVector(integers_2);

    // Use inequality operator with 'vector' objects.
    cout << "\n" "Evaluating: 'integers_1' != 'integers_2'" << endl;

    if (integers_1 != integers_2) {
        cout << "'integers_1' and 'integers_2' are not equal" << endl;
    }

    // Create vector 'integers_3' using 'integers_1' as an initializer;
    // print size and contents.
    vector<int> integers_3 {integers_1}; // copy constructor

    cout \
        << "\n" "Size of vector 'integers_3' is " << integers_3.size()
        << "\n" "vector after initialization: ";
    OutputVector(integers_3);

    // Use overloaded assignment operator.
    cout << "\n" "Assigning 'integers_2' to 'integers_1':" << endl;
    integers_1 = integers_2;

    cout << "'integers_1': ";
    OutputVector(integers_1);
    cout << "'integers_2': ";
    OutputVector(integers_2);

    // Use equality operator with vector objects.
    cout << "\n" "Evaluating: 'integers_1' == 'integers_2'" << endl;

    if (integers_1 == integers_2) {
        cout << "'integers_1' and 'integers_2' are equal" << endl;
    }

    // Use square brackets to use the value at location 5 as an rvalue.
    cout << "\n" "integers_1[5] is " << integers_1[5];

    // Use square brackets to create lvalue.
    cout << "\n\n" "Assigning 1000 to integers_1[5]" << endl;
    integers_1[5] = 1000;
    cout << "'integers_1': ";
    OutputVector(integers_1);

    // Attempt to use out-of-range subscript.
    try {
        cout << "\n" "Attempt to display integers_1.at(15)" << endl;
        cout << integers_1.at(15) << endl; // out of range
    } catch (out_of_range &out_of_range_exception) {
        cerr \
            << "An exception occurred: "
            << out_of_range_exception.what() << endl;
    }

    // Changing the size of a 'vector'.
    cout << "\n" "Current 'integers_3' size is: " << integers_3.size() << endl;
    integers_3.push_back(1000); // add 1000 to the end of the vector
    cout << "New 'integers_3' size is: " << integers_3.size() << endl;
    cout << "'integers_3' now contains: ";
    OutputVector(integers_3);

    return 0;
}

/**
 * Output vector contents.
 */
static void OutputVector(const vector<int> &items)
{
    for (auto const &item : items) {
        cout << item << " ";
    }
    cout << endl;
}

/**
 * Input vector contents.
 */
static void InputVector(vector<int> &items)
{
    for (auto &item : items) {
        cin >> item;
    }
}
