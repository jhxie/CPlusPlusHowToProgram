/**
 * 5.18
 * Logical operators.
 */

#include <iostream>

using namespace std;

int main(void)
{
    // Create truth table for logical AND operator.
    cout \
        << boolalpha << "Logical AND (&&)"
        << "\nfalse && false: " << (false && false)
        << "\nfalse && true:  " << (false && true)
        << "\ntrue  && false: " << (true && false)
        << "\ntrue  && true:  " << (true && true) << "\n\n";

    // Create truth table for logical OR operator.
    cout \
        << "Logical OR (||)"
        << "\nfalse || false: " << (false || false)
        << "\nfalse || true:  " << (false || true)
        << "\ntrue  || false: " << (true || false)
        << "\ntrue  || true:  " << (true || true) << "\n\n";

    // Create truth table for logical negation operator.
    cout \
        << "Logical negation (!)"
        << "\n!false: " << (!false)
        << "\n!true:  " << (!true) << endl;
    return 0;
}
