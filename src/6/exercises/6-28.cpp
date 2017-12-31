/**
 * @section DESCRIPTION
 *
 * Perfect Numbers.
 *
 * An integer is said to be a perfect number if the sum of its divisors,
 * including 1 (but not the number itself), is equal to the number. For
 * example, 6 is a perfect number, because 6=1+2+3. Write a function isPerfect
 * that determines whether parameter number is a perfect number. Use this
 * function in a program that determines and prints all the perfect numbers
 * between 1 and 1000. Print the divisors of each perfect number to confirm
 * that the number is indeed perfect. Challenge the power of your computer by
 * testing numbers much larger than 1000.
 */

#include <boost/multiprecision/cpp_int.hpp>
#include <iomanip>
#include <iostream>
#include <set>
#include <memory>

using boost::multiprecision::pow;
using boost::multiprecision::sqrt;
using boost::multiprecision::uint128_t;
using std::cout;
using std::endl;
using std::set;
using std::setw;
using std::unique_ptr;

using int_set_ptr = unique_ptr<set<uint128_t>>;

template <class T>
struct Accumulator final
{
    Accumulator() : sum {0}
    {
    }

    void operator()(const T &input)
    {
        sum += input;
    }
public:
    T sum;
};

static int_set_ptr FindDivisors(const uint128_t &number)
{
    int_set_ptr divisor_set_ptr {new set<uint128_t>};
    const uint128_t kDivisorLimit {sqrt(number)};

    // Base Case:
    // 1 does not have any valid candidate divisor to be considered as a
    // potential perfect number.
    if (number <= 1) {
        return divisor_set_ptr;
    }

    divisor_set_ptr->insert(1);

    for (uint128_t i {2}; i <= kDivisorLimit; ++i) {
        if (number % i == 0) {
            divisor_set_ptr->insert(i);
            divisor_set_ptr->insert(number / i);
        }
    }
    return divisor_set_ptr;
}

static bool IsPerfectNumber(const uint128_t &number,
                            int_set_ptr &divisor_set_ptr)
{
    // Compiler would use copy elision, so a 'move' in unnecessary.
    divisor_set_ptr = FindDivisors(number);

    if (divisor_set_ptr->size() == 0) {
        return false;
    }

    Accumulator<uint128_t> accumulator;

    for (auto &i : *divisor_set_ptr) {
        accumulator(i);
    }

    return accumulator.sum == number;
}

int main(void)
{
    static constexpr int kWidthLeft {15}, kWidthRight {40};
    int_set_ptr divisor_set_ptr;

    cout \
        << setw(kWidthLeft) << "Perfect Number"
        << setw(kWidthRight) << "Divisors" << endl;

    for (uint128_t i = 1; i <= uint128_t(1) << 16; ++i) {
        if (IsPerfectNumber(i, divisor_set_ptr)) {
            cout << setw(kWidthLeft) << i << setw(kWidthRight);
            for (auto divisor_iterator = divisor_set_ptr->cbegin();
                 divisor_iterator != divisor_set_ptr->cend();
                 ++divisor_iterator) {
                cout << *divisor_iterator;
                if (++divisor_iterator == divisor_set_ptr->cend()) {
                    --divisor_iterator;
                    cout << endl;
                } else {
                    --divisor_iterator;
                    cout << ", ";
                }
            }
        }
    }
    return 0;
}
