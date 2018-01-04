/**
 *
 * @section DESCRIPTION
 *
 * Dice Rolling.
 *
 * Write a program that simulates the rolling of two dice.
 * The sum of the two values should then be calculated.
 *
 * [Note: Each die can show an integer value from 1 to 6, so the sum of the two
 * values will vary from 2 to 12, with 7 being the most frequent sum and 2 and
 * 12 being the least frequent sums.]
 *
 * Figure 7.22 shows the 36 possible combinations of the two dice. Your program
 * should roll the two dice 36,000,000 times.
 * Use a one-dimensional array to tally the numbers of times each possible sum
 * appears.
 *
 * Print the results in a tabular format. Also, determine if the totals are
 * reasonable (i.e., there are six ways to roll a 7, so approximately one-sixth
 * of all the rolls should be 7).
 */

#include <array>
#include <cstdio>
#include <ctime>
#include <random>

using namespace std;

using uint = unsigned int;
using ulong = unsigned long;

static uint RollTwoDiceSum()
{
    static constexpr int kDieRolls = 2;
    static default_random_engine engine {
        static_cast<uint>(time(0))
    };

    uniform_int_distribution<uint> random_die_roll {1, 6};
    uint dice_roll_sum {0};

    for (int i {0}; i < kDieRolls; ++i) {
        dice_roll_sum += random_die_roll(engine);
    }

    return dice_roll_sum;
}

int main(void)
{
    static constexpr ulong kDiceRolls = 36'000'000UL;
    // The size needed is calculated as (inclusive valid number range) + shift.
    static constexpr size_t kDiceSumCombinations = (12 - 2 + 1) + 2;
    array<ulong, kDiceSumCombinations> two_dice_roll_sum_frequency {};

    for (ulong i {0}; i < kDiceRolls; ++i) {
        ++two_dice_roll_sum_frequency[RollTwoDiceSum()];
    }

    static constexpr int kWidthLeft {20}, kWidthRight {30};
    printf("%*s%*s\n",
           kWidthLeft, "Two Dice Roll Sum",
           kWidthRight, "Frequency");
    for (size_t i {2}; i < two_dice_roll_sum_frequency.size(); ++i) {
        printf("%*zu%*ld\n",
               kWidthLeft, i,
               kWidthRight, two_dice_roll_sum_frequency[i]);
    }
    return 0;
}
