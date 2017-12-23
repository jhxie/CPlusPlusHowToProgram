#include <iostream>
#include <string>

int main(void)
{
#ifdef PRINT_DEBUG_INFO
#endif

    using namespace std;

    // Declare a variable to store an integer
    int input_number;
    string input_name;

    cout << "Enter an integer: ";

    // Store the integer given by user input (stream extraction operator)
    cin >> input_number;

    // The same with text
    cout << "Enter your name: ";
    cin >> input_name;
    cout << input_name << " entered number " << input_number << endl;
    return 0;
}
