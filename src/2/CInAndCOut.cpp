#include <iostream>
#include <string>

int main(void)
{
#ifdef PRINT_DEBUG_INFO
#endif

    using namespace std;

    // Declare a variable to store an integer
    int InputNumber;
    string InputName;

    cout << "Enter an integer: ";

    // Store the integer given by user input (stream extraction operator)
    cin >> InputNumber;

    // The same with text
    cout << "Enter your name: ";
    cin >> InputName;
    cout << InputName << " entered number " << InputNumber << endl;
    return 0;
}
