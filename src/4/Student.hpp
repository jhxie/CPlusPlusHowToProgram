/**
 * 'Student' class that stores name and average.
 */
#pragma once

#include <string>


class Student final {
public:
    Student(std::string student_name, int student_average)
        : name_(student_name) {
        SetAverage(student_average);
    }

/* =============================== Mutators ================================ */
    void SetName(std::string student_name) {
        name_ = student_name;
    }

    void SetAverage(int student_average) {
        // Selection statements nesting.
        // Validate that 'student_average' is in the range of (0, 100];
        // otherwise, keep data member average's current value.
        if (student_average > 0) {
            if (student_average <= 100) {
                average_ = student_average;
            }
        }
    }
/* =============================== Mutators ================================ */

/* ============================== Accessors ================================ */
    std::string GetName() const {
        return name_;
    }

    int GetAverage() const {
        return average_;
    }

    std::string GetLetterGrade() const {
        // Initialized to empty string by its default constructor.
        std::string letter_grade;

        if (GetAverage() >= 90) {
            letter_grade = "A";
        } else if (GetAverage() >= 80) {
            letter_grade = "B";
        } else if (GetAverage() >= 70) {
            letter_grade = "C";
        } else if (GetAverage() >= 60) {
            letter_grade = "D";
        } else {
            letter_grade = "F";
        }

        return letter_grade;
    }
/* ============================== Accessors ================================ */
private:
    std::string name_;
    int average_{0};
};
