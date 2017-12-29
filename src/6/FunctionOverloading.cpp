/**
 * 6.20
 * Overloaded square functions.
 */

#include <iostream>

using namespace std;

/**
 * Function 'Square' for int values.
 */
int Square(int x)
{
#ifdef PRINT_DEBUG_INFO
    cout << "Square of integer " << x << " is ";
#endif
    return x * x;
}

/**
 * Function 'Square' for double values.
 */
double Square(double y)
{
#ifdef PRINT_DEBUG_INFO
    cout << "Square of double " << y << " is ";
#endif
    return y * y;
}

int main(void)
{
    cout << Square(7);   // calls int version
    cout << endl;
    cout << Square(7.5); // calls double version
    cout << endl;
    return 0;
}
