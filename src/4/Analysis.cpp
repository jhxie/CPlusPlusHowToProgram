/**
 * 4.14
 * Analysis of examination results using nested control statements.
 */

#include <iostream>

using namespace std;

enum
{
    FAILURE,
    PASS,
    SIZE
};

int main(void)
{
    // Initializing variables in declarations.
    const unsigned int NUMBER_OF_STUDENTS {10U};
    const double BONUS_PERCENTAGE {0.8};
    const unsigned int BONUS_THRESHOLD {
        static_cast<unsigned int>(BONUS_PERCENTAGE * NUMBER_OF_STUDENTS)
    };
    unsigned int summary[SIZE] {0U, 0U};
    int result {0};

    for (unsigned int counter = 0U; counter < NUMBER_OF_STUDENTS; ++counter) {
        cout << "Enter result (1 = pass, 2 = fail): ";
        cin >> result;

        if (result == 1) {
            summary[PASS]++;
        } else {
            summary[FAILURE]++;
        }
    }

    // Termination phase; prepare and display results.
    cout \
        << "Passed: " << summary[PASS]
        << "\nFailed: " << summary[FAILURE] << endl;

    // Determine whether more than 80% students passed.
    if (summary[PASS] > BONUS_THRESHOLD) {
        cout << "Bonus to instructor!" << endl;
    }
    return 0;
}
