/**
 * @section DESCRIPTION
 *
 * Show the value of x after each of the following statements is performed:
 *
 * x = fabs(7.5);
 *
 * x = floor(7.5);
 *
 * x = fabs(0.0);
 *
 * x = ceil(0.0);
 *
 * x = fabs(-6.4);
 *
 * x = ceil(-6.4);
 *
 * x = ceil(-fabs(-8 + floor(-5.5)));
 */

#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double x {.0};

    cout << fixed << setprecision(2);

    x = fabs(7.5); // x == 7.5

    cout << x << endl;

    x = floor(7.5); // x == 7

    cout << x << endl;

    x = fabs(0.0); // x == 0

    cout << x << endl;

    x = ceil(0.0); // x == 0

    cout << x << endl;

    x = fabs(-6.4); // x == 6.4

    cout << x << endl;

    x = ceil(-6.4); // x == -6

    cout << x << endl;

    x = ceil(-fabs(-8 + floor(-5.5))); // x == -14

    cout << x << endl;
    return 0;
}
