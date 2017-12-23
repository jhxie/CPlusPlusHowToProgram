/**
 * 5.11
 * Using a switch statement to count letter grades.
 */

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <memory>

using namespace std;

int main(void)
{
    int total {0}; // sum of grades
    unsigned int grade_counter {0U}; // number of grades entered
    enum GradeLetter {
        A, B, C, D, F, Count
    };
    array<enum GradeLetter, static_cast<int>(Count)> grade_letter_array {
        {A, B, C, D, F}
    };
    unordered_map<GradeLetter, unsigned int> grade_map;

    for (auto i : grade_letter_array) {
        grade_map[i] = {0U};
    }

    cout \
        << "Enter the integer grades in the range 0-100.\n"
        << "Type the end-of-file indicator to terminate input:\n"
        << "   On UNIX/Linux/Mac OS X type <Ctrl> d then press Enter\n"
        << "   On Windows type <Ctrl> z then press Enter\n";

    int grade;

    // Loop until user enters the end-of-file indicator.
    while (cin >> grade) {
        total += grade; // add grade to total
        ++grade_counter; // increment number of grades

        // increment appropriate letter-grade counter
        switch (grade / 10) {

        // Grade was in range [90, 100]
        case 9:
        case 10:
            ++grade_map[A];
            break; // exits switch

        // Grade was in range [80, 89]
        case 8:
            ++grade_map[B];
            break;

        // Grade was in range [70, 79]
        case 7:
            ++grade_map[C];
            break;

        // Grade was in range [60, 69]
        case 6:
            ++grade_map[D];
            break;

        default:
            ++grade_map[F];
        }
    }

    // Set floating-point number format.
    cout << fixed << setprecision(2);

    // Display grade report
    cout << "\nGrade Report:\n";

    // If user entered at least one grade.
    if (grade_counter != 0) {
        // Calculate average of all grades entered.
        double average = static_cast<double>(total) / grade_counter;

        cout \
            << "Total of the " << grade_counter << " grades entered is "
            << total << "\nClass average is " << average
            << "\nNumber of students who received each grade:"
            << "\nA: " << grade_map[A] << "\nB: " << grade_map[B]
            << "\nC: " << grade_map[C] << "\nD: " << grade_map[D]
            << "\nF: " << grade_map[F] << endl;
    } else {
        cout << "No grades were entered" << endl;
    }

    return 0;
}
