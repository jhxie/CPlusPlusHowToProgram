/**
 * 6.7
 * Rolling a six-sided die 60,000,000 times.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    static constexpr int kDiceFaceCount {6};
    static constexpr unsigned int kDiceRollTotal {60'000'000U};
    unordered_map<unsigned int, unsigned int> dice_frequency;
    int face {0}; // stores each roll of the die

    for (unsigned int key {1U}; key <= kDiceFaceCount; ++key) {
        dice_frequency[key] = 0U;
    }

    // Summarize results of 60,000,000 rolls of a die.
    for (unsigned int roll {1}; roll <= kDiceRollTotal; ++roll) {
        face = 1 + rand() % kDiceFaceCount; // random number from 1 to 6

        // Determine roll value 1-6 and increment appropriate bucket counter.
        ++dice_frequency[static_cast<unsigned int>(face)];
    }

    static constexpr const char *const kHeaderA = "Face";
    static constexpr const char *const kHeaderB = "Frequency";
    static constexpr int kFaceWidth {4}, kResultWidth {13};

    for (unsigned int key {0U}; key <= kDiceFaceCount; ++key) {
        if (key == 0U) {
            cout \
                << setw(kFaceWidth) << kHeaderA
                << setw(kResultWidth) << kHeaderB << endl;
        } else {
            cout \
                << setw(kFaceWidth) << key
                << setw(kResultWidth) << dice_frequency[key] << '\n';
        }
    }
    cout << endl;
    return 0;
}
