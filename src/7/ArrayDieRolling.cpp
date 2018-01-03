/**
 * 7.8
 * Die-rolling program using an array instead of switch.
 */

#include <array>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main(void)
{
    // Use the default random-number generation engine to produce uniformly
    // distributed pseudorandom int values from 1 to 6.
    default_random_engine engine (static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> random_int (1, 6);

    static constexpr size_t kArraySize{7}; // ignore element zero
    array<unsigned int, kArraySize> die_frequency {}; // initialize to 0s

    // Roll die 60,000,000 times; use die value as frequency index.
    for (unsigned int roll{1}; roll <= 60'000'000U; ++roll) {
        ++die_frequency[random_int(engine)];
    }

    static constexpr int kWidth {13};
    cout << "Face" << setw(kWidth) << "Frequency" << endl;

    // Output each array element's value.
    for (size_t face {1}; face < die_frequency.size(); ++face) {
        cout << setw(4) << face << setw(kWidth) << die_frequency[face] << endl;
    }
    return 0;
}
