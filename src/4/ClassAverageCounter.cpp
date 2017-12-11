/**
 * Solve the class-average problem using counter-controlled iteration.
 */

#include <iostream>

using namespace std;

int main(void)
{
    // Initialization phase.
    int average {0};
    int total {0};
    int grade {0};
    unsigned int gradeCounter {0};
    const int NUMBER_OF_STUDENTS {10};

    // Processing phase uses counter-controlled iteration.
    while (gradeCounter < NUMBER_OF_STUDENTS) { // Loop 10 times (9 - 0 + 1)
        cout << "Enter grade: "; // Prompt
        grade = 0;
        cin >> grade; // Input next grade
        total += grade; // Add grade to total
        gradeCounter++;
    }

    // Termination phase.
    average = total / NUMBER_OF_STUDENTS; // int division yields int result

    // Display total and average of grades.
    cout << "\nTotal of all " << NUMBER_OF_STUDENTS << " grades is " << total;
    cout << "\nClass average is " << average << endl;
    return 0;
}
