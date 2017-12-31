/**
 * @section DESCRIPTION
 *
 * Square of Any Character.
 *
 * Modify the function created in Exercise 6.22 to form the square out of
 * whatever character is contained in character parameter fillCharacter. Thus,
 * if side is 5 and fillCharacter is #, then this function should print the
 * following:
 *
 * #####
 * #####
 * #####
 * #####
 * #####
 */

#include <iostream>

using namespace std;

using uint = unsigned int;

static void DisplaySquare(const uint &side, const char &fill_character)
{
    for (uint i {0U}; i < side; ++i) {
        for (uint j {0U}; j < side; ++j) {
            cout << fill_character;
        }
        cout << '\n';
    }
    cout << endl;
}

int main(void)
{
    uint side {0U};
    char fill_character {};
    cout << "Enter the length of the square: ";
    if (cin >> side) {
        cout << "Enter the character to be filled: ";

        if (cin >> fill_character) {
            DisplaySquare(side, fill_character);
        }
    }
    return 0;
}
