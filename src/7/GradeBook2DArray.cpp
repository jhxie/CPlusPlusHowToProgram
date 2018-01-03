/**
 * 7.19
 * Definition of class 'GradeBook' that uses a two-dimensional array to store
 * test grades.
 */

#include "GradeBook2DArray.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

GradeBook::GradeBook(const std::string &name,
          const std::array<std::array<int, kTests>, kStudents> &grades_array)
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

    // Call functions 'GetMinimum' and 'GetMaximum'.
    cout \
        << "\n"
        << "Lowest grade in the grade book is " << GetMinimum() << "\n"
        << "Highest grade in the grade book is " << GetMaximum() << endl;

    OutputBarChart(); // display grade distribution chart
}

int GradeBook::GetMinimum() const
{
    int low_grade {100};

    // Loop through rows of 'grades_' array.
    for (auto const &student : grades_) {
        // Loop through columns of current row.
        for (auto const &grade : student) {
            // If current 'grade' is lower than 'low_grade', replace it.
            if (grade < low_grade) {
                low_grade = grade;
            }
        }
    }

    return low_grade;
}

int GradeBook::GetMaximum() const
{
    int high_grade {0};

    // Loop through rows of 'grades_' array.
    for (auto const &student : grades_) {
        // Loop through columns of current row.
        for (auto const &grade : student) {
            // If current 'grade' is higher than 'high_grade', replace it.
            if (grade > high_grade) {
                high_grade = grade;
            }
        }
    }

    return high_grade;
}

long double
GradeBook::GetAverage(const array<int, GradeBook::kTests> &grades_set)
{
    long total {0};

    // Sum grades in array.
    for (const int &grade : grades_set) {
        total += grade;
    }

    // Return average of grades.
    return static_cast<long double>(total) / grades_set.size();
}

void GradeBook::OutputBarChart() const
{
    cout << "\n" "Overall Grade Distribution:" << endl;

    // Stores frequency of grades in each range of 10 grades - [0, 100].
    static constexpr size_t kFrequencySize {11};
    array<unsigned int, kFrequencySize> frequency {};

    // For each grade, increment the appropriate frequency.
    for (auto const &student : grades_) {
        for (auto const &test : student) {
            ++frequency[static_cast<size_t>(test / 10)];
        }
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
    cout << "\nThe grades are:" "\n\n";
    cout << "            "; // align column heads

    // Create a column heading for each of the tests.
    for (size_t test {0}; test < kTests; ++test) {
        cout << "Test " << test + 1 << "  ";
    }

    cout << "Average" << endl;

    // Create rows/columns of text representing array grades.
    for (size_t student {0}; student < grades_.size(); ++student) {
        cout << "Student " << setw(2) << student + 1;

        // Output student's grades.
        for (size_t test {0}; test < grades_[student].size(); ++test) {
            cout << setw(8) << grades_[student][test];
        }

        // Call member function 'GetAverage' to calculate student's average;
        // pass one row of grades as the argument.
        long double average {
            GetAverage(grades_[student])
        };

        cout << setw(9) << setprecision(2) << fixed << average << endl;
    }
}
/* =============================== Accessors =============================== */
