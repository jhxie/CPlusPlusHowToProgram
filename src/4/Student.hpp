/**
 * 'Student' class that stores name and average.
 */
#pragma once

#include <string>


class Student final {
public:
    Student(std::string studentName, int studentAverage) : name(studentName) {
        setAverage(studentAverage);
    }

/* =============================== Mutators ================================ */
    void setName(std::string studentName) {
        name = studentName;
    }

    void setAverage(int studentAverage) {
        // Selection statements nesting.
        // Validate that 'studentAverage' is in the range of (0, 100];
        // otherwise, keep data member average's current value.
        if (studentAverage > 0) {
            if (studentAverage <= 100) {
                average = studentAverage;
            }
        }
    }
/* =============================== Mutators ================================ */

/* ============================== Accessors ================================ */
    std::string getName() const {
        return name;
    }

    int getAverage() const {
        return average;
    }

    std::string getLetterGrade() const {
        // Initialized to empty string by its default constructor.
        std::string letterGrade;

        if (getAverage() >= 90) {
            letterGrade = "A";
        } else if (getAverage() >= 80) {
            letterGrade = "B";
        } else if (getAverage() >= 70) {
            letterGrade = "C";
        } else if (getAverage() >= 60) {
            letterGrade = "D";
        } else {
            letterGrade = "F";
        }

        return letterGrade;
    }
/* ============================== Accessors ================================ */
private:
    std::string name;
    int average{0};
};
