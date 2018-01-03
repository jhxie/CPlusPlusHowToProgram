/**
 * 7.14
 * Creates 'GradeBook' object using an array of grades.
 */

#include "GradeBookSingleArray.hpp"

#include <array>

using namespace std;

int main(void)
{
    // Array of student grades.
    static constexpr array<int, GradeBook::kStudents> kGrades {
        {87, 68, 94, 100, 83, 78, 85, 91, 76, 87}
    };
    static const string kCourseName {
        "CS101 Introduction to C++ Programming"
    };

    GradeBook my_gradebook(kCourseName, kGrades);
    my_gradebook.DisplayMessage();
    my_gradebook.ProcessGrades();
    return 0;
}
