/**
 * Create and test 'Student' objects.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Student.hpp"

using namespace std;

int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Student student {"Jane Green", 0};
    int average;

    for (int skew = 90; skew > 40; skew -= 10) {
        average = rand() % 10 + skew;
        student.SetAverage(average);
        cout << student.GetName() << "'s letter grade equivalent of "
            << student.GetAverage() << " is: "
            << student.GetLetterGrade() << endl;
    }
    return 0;
}
