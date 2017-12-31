/**
 * @section DESCRIPTION
 *
 * Random Numbers.
 *
 * Write a single statement that prints a number at random from each of the
 * following sets:
 *
 * 2, 4, 6, 8, 10.
 *
 * 3, 5, 7, 9, 11.
 *
 * 6, 10, 14, 18, 22.
 *
 * 'DieStatisticalPRNG.cpp' is used as a reference.
 */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

template <class T>
static void PrintSequence(const vector<T> &sequence)
{
    cout << "A random number picked from set:\n";
    for (decltype(sequence.size()) i {0}; i < sequence.size(); ++i) {
        cout << sequence[i] << (i == sequence.size() - 1 ? "." : ", ");
    }
    cout << endl;
}

template <class T>
class Incrementor
{
public:
    Incrementor(T initial_value) : value_(initial_value)
    {
    }

    virtual ~Incrementor()
    {
    }

    const T &value() const
    {
        return value_;
    }

    void value(T new_value)
    {
        value_ = new_value;
    }

    virtual void operator()(T &input)
    {
        input += value();
    }
private:
    T value_;
};

template <class T>
class Multiplicator : public Incrementor<T>
{
public:
    Multiplicator(T value) : Incrementor<T>(value)
    {
    }

    virtual void operator()(T &input) override
    {
        input *= Incrementor<T>::value();
    }
};

int main(void)
{
    default_random_engine engine {static_cast<unsigned int>(time(0))};
    uniform_int_distribution<int> random_int {1, 5}; // range is [1, 5]
    vector<int> sequence {2, 4, 6, 8, 10};

    PrintSequence(sequence);
    cout << "The number picked is: " << random_int(engine) * 2 << endl;

    Incrementor<int> incrementor {1};
    // Add 1 to each value in the 'sequence' as both are arithmetic sequence.
    for_each(sequence.begin(), sequence.end(), incrementor);
    PrintSequence(sequence);
    cout << "The number picked is: " << random_int(engine) * 2 + 1 << endl;

    Multiplicator<int> multiplicator {2};
    // Multiply each value by 2 in the 'sequence'.
    for_each(sequence.begin(), sequence.end(), multiplicator);
    PrintSequence(sequence);
    cout << "The number picked is: " << random_int(engine) * 4 + 2 << endl;

    return 0;
}
