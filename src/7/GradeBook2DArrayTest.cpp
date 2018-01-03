/**
 * 7.20
 * Creates 'GradeBook' object using a two-dimensional array of grades.
 */

#include "GradeBook2DArray.hpp"

#include <array>

using namespace std;

int main(void)
{
    using GradeBookArray = array<array<int, GradeBook::kTests>,
                                 GradeBook::kStudents>;
    // Two-dimensional array of student grades.
    static constexpr GradeBookArray kGrades {
        {
            {{87, 96, 70}},
            {{68, 87, 90}},
            {{94, 100, 90}},
            {{100, 81, 82}},
            {{83, 65, 85}},
            {{78, 87, 65}},
            {{85, 75, 83}},
            {{91, 94, 100}},
            {{76, 72, 84}},
            {{87, 93, 73}}
        }
    };
    static const string kCourseName {
        "CS101 Introduction to C++ Programming"
    };

    GradeBook my_gradebook(kCourseName, kGrades);
    my_gradebook.DisplayMessage();
    my_gradebook.ProcessGrades();
    return 0;
}
