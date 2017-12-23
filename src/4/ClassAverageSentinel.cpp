/**
 * 4.10.3
 * Solve the class-average problem using sentinel-controlled iteration.
 */

#include <iostream>
#include <iomanip> // Parameterized stream manipulators

using namespace std;

int main(void)
{
    // Initialization phase.
    int total {0}; // sum of grades
    int grade {-1};
    unsigned int grade_counter {0}; // number of grades entered so far

    // Processing phase.
    do {
        if (grade != -1) {
            total += grade;
            grade_counter++;
        }
        // Prompt for input and read next value from user
        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    } while (grade != -1);

    // Termination phase.
    if (grade_counter != 0) {
        double average {static_cast<double>(total) / grade_counter};

        // Display total and average (with two digits of precision)
        cout \
            << "\nTotal of the " << grade_counter
            << " grades entered is " << total;
        // NOTE:
        // Without the 'fixed' stream manipulator double values without
        // fractions would display without trailing zeroes.
        cout << setprecision(2) << fixed;
        cout << "\nClass average is " << average << endl;
    } else {
        cout << "No grades were entered" << endl;
    }
    return 0;
}
