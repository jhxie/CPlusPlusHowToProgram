/**
 * 6.9
 * Craps simulation.
 *
 * From 6.8 (Chapter 6 Section 8) of
 * C++ How to Program, 10th Edition
 * "
 * A player rolls two dice. Each die has six faces. These faces contain 1, 2,
 * 3, 4, 5 and 6 spots. After the dice have come to rest, the sum of the spots
 * on the two upward faces is calculated. If the sum is 7 or 11 on the first
 * roll, the player wins. If the sum is 2, 3 or 12 on the first roll (called
 * “craps”), the player loses (i.e., the “house” wins). If the sum is 4, 5, 6,
 * 8, 9 or 10 on the first roll, then that sum becomes the player’s “point.” To
 * win, you must continue rolling the dice until you “make your point.” The
 * player loses by rolling a 7 before making the point.
 * "
 */

#include <cstdlib> // contains prototypes for functions 'srand' and 'rand'
#include <ctime>   // contains prototype for function 'time'
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unsigned int RollDice(); // rolls dice, calculates and displays sum

int main(void)
{
    // Scoped enumeration with constants that represent the game status.
    enum class Status : unsigned int {
        CONTINUE,
        LOST,
        WON
    };

    // Randomize PRNG using current time.
    srand(static_cast<unsigned int>(time(0)));

    unsigned int my_point {0U}; // point if no win or loss on first roll
    Status game_status;
    unsigned int sum_of_dice {RollDice()}; // first roll of the dice

    // Determine game status and point (if needed) based on first roll
    switch (sum_of_dice) {
    // Win with '7' or '11' on first roll.
    case 7:
    case 11:
        game_status = Status::WON;
        break;
    // Lose with '2', 3', '12' on first roll.
    case 2:
    case 3:
    case 12:
        game_status = Status::LOST;
        break;
    // Did not win or lose, so remember point.
    default:
        game_status = Status::CONTINUE;
        my_point = sum_of_dice; // remember the point
        cout << "Point is " << my_point << endl;
    }

    while (game_status == Status::CONTINUE) {
        sum_of_dice = RollDice(); // roll dice again

        // Determine game status; win by making point.
        if (sum_of_dice == my_point) {
            game_status = Status::WON;
        // Lose by rolling 7 before point.
        } else if (sum_of_dice == 7) {
            game_status = Status::LOST;
        }
    }

    unordered_map<Status, string> message = {
        {Status::LOST, "Player loses!"},
        {Status::WON, "Player wins!"},
    };
    // Display won or lost message
    cout << message[game_status] << endl;
    return 0;
}

unsigned int RollDice()
{
    auto roll = []() -> int {
        return 1 + rand() % 6;
    };
    int die_1 {roll()}; // first die roll
    int die_2 {roll()}; // second die roll
    int sum {die_1 + die_2};

    // Display results of this roll.
    cout \
        << "Player rolled " << die_1 << " + " << die_2 << " = " << sum << endl;
    return static_cast<unsigned int>(sum);
}
