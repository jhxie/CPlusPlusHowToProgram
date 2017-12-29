/**
 * 6.17
 * Passing arguments by value and by reference.
 */

#include <iostream>

using namespace std;

int SquareByValue(int);
void SquareByReference(int &);

int main(void)
{
    int x {2}; // value to square using 'SquareByValue'
    int z {4}; // value to square using 'SquareByReference'

    // Demonstrate 'SquareByValue'.
    cout << "'x' = " << x << " before 'SquareByValue'\n";
    cout << "Value returned by 'SquareByValue': " << SquareByValue(x) << endl;
    cout << "'x' = " << x << " after 'SquareByValue'\n" << endl;

    // Demonstrate 'SquareByReference'.
    cout << "'z' = " << z << " before 'SquareByReference'" << endl;
    SquareByReference(z);
    cout << "'z' = " << z << " after 'SquareByReference'" << endl;
    return 0;
}

/**
 * 'SquareByValue' multiplies 'number' by itself, stores the result in 'number'
 * and returns the new value of 'number'.
 */
int SquareByValue(int number)
{
    return number *= number; // caller's argument not modified
}

/**
 * 'SquareByReference' multiplies 'number_reference' by itself and stores the
 * result in the variable to which 'number_reference' refers in function
 * 'main'.
 */
void SquareByReference(int &number_reference)
{
    number_reference *= number_reference; // caller's argument modified
}
