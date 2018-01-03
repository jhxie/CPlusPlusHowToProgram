/**
 * 7.19
 * Declaration of class 'GradeBook' that uses a two-dimensional array to store
 * test grades.
 */

#pragma once

#include <array>
#include <cstddef>
#include <string>

class GradeBook final
{
public:
    /**
        Constant number of students who took the test.
     */
    static constexpr size_t kStudents {10};

    /**
     * Constant number of tests.
     */
    static constexpr size_t kTests {3};

    /**
     * Constructor initializes 'course_name' and 'grades' array.
     */
    GradeBook(const std::string &name,
              const std::array<std::array<int, kTests>, kStudents>
              &grades_array);

/* ================================ Mutator ================================ */
    /**
     * Function to set the course name.
     */
    void SetCourseName(const std::string &name);
/* ================================ Mutator ================================ */

/* =============================== Accessors =============================== */
    /**
     * Function to retrieve the course name.
     */
    const std::string &GetCourseName() const;

    /**
     * Display a welcome message to the 'GradeBook' user.
     */
    void DisplayMessage() const;

    /**
     * Perform various operations on the data (none modify the data).
     */
    void ProcessGrades() const;

    /**
     * Find minimum grade.
     */
    int GetMinimum() const;

    /**
     * Find maximum grade.
     */
    int GetMaximum() const;

    /**
     * Determine average grade for particular set of grades.
     */
    static long double GetAverage(const std::array<int, kTests> &grades_set);

    /**
     * Output bar chart displaying grade distribution.
     */
    void OutputBarChart() const;

    /**
     * Output the contents of the 'grades_' array.
     */
    void OutputGrades() const;
/* =============================== Accessors =============================== */

private:
    std::string course_name_;
    std::array<std::array<int, kTests>, kStudents> grades_; // 2D array
};
