/**
 * 7.13
 * Definition of class 'GradeBook' that uses an array to store test grades.
 */

#include "GradeBookSingleArray.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

GradeBook::GradeBook(const string &name,
                     const array<int, kStudents> &grades_array)
    : course_name_{name}, grades_{grades_array}
{
}

/* ================================ Mutator ================================ */
void GradeBook::SetCourseName(const string &name)
{
    course_name_ = name;
}
/* ================================ Mutator ================================ */

/* =============================== Accessors =============================== */

const string &GradeBook::GetCourseName() const
{
    return course_name_;
}

void GradeBook::DisplayMessage() const
{
    // Call 'GetCourseName' to get the name of this 'GradeBook''s course.
    cout\
        << "Welcome to the grade book for\n"
        << GetCourseName() << "!" << endl;
}

void GradeBook::ProcessGrades() const
{
    OutputGrades(); // output 'grades_' array

    // Call function 'GetAverage' to calculate tge average grade.
    cout << setprecision(2) << fixed;
    cout << "\nClass average is " << GetAverage() << endl;

    // Call functions 'GetMinimum' and 'GetMaximum'.
    cout \
        << "Lowest grade is " << GetMinimum() << "\n"
        << "Highest grade is " << GetMaximum() << endl;

    OutputBarChart(); // display grade distribution chart
}

int GradeBook::GetMinimum() const
{
    int low_grade {100};

    // Loop through 'grades_' array.
    for (const int &grade : grades_) {
        // If current 'grade' is lower than 'low_grade', replace it.
        if (grade < low_grade) {
            low_grade = grade;
        }
    }

    return low_grade;
}

int GradeBook::GetMaximum() const
{
    int high_grade {0};

    // Loop through 'grades_' array.
    for (const int &grade : grades_) {
        // If current 'grade' is higher than 'high_grade', replace it.
        if (grade > high_grade) {
            high_grade = grade;
        }
    }

    return high_grade;
}

long double GradeBook::GetAverage() const
{
    long total {0};

    // Sum grades in array.
    for (const int &grade : grades_) {
        total += grade;
    }

    // Return average of grades.
    return static_cast<long double>(total) / grades_.size();
}

void GradeBook::OutputBarChart() const
{
    cout << "\n" "Grade Distribution:" << endl;

    // Stores frequency of grades in each range of 10 grades - [0, 100].
    static constexpr size_t kFrequencySize {11};
    array<unsigned int, kFrequencySize> frequency {};

    // For each grade, increment the appropriate frequency.
    for (const int &grade : grades_) {
        ++frequency[static_cast<size_t>(grade / 10)];
    }

    // For each grade frequency, print bar in chart.
    for (size_t i {0}; i < kFrequencySize; ++i) {
        // Output bar labels (0-9, ... 90-99, 100).
        if (i == 0) {
            cout << "  0-9: ";
        } else if (i == 10) {
            cout << "  100: ";
        } else {
            cout << i * 10 << "-" << (i * 10) + 9 << ": ";
        }

        // Print bar of asterisks.
        for (unsigned int stars {0}; stars < frequency[i]; ++stars) {
            cout << "*";
        }
        cout << endl;
    }
}

void GradeBook::OutputGrades() const
{
    cout << "\n" "The grades are:" "\n\n";

    // Output each student's grade.
    for (size_t student {0}; student < grades_.size(); ++student) {
        cout \
            << "Student " << setw(2) << student + 1 << ": "
            << setw(3) << grades_[student] << endl;
    }
}
/* =============================== Accessors =============================== */
