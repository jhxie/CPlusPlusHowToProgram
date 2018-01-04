/**
 *
 * @section DESCRIPTION
 *
 * Knight’s Tour.
 *
 * One of the more interesting puzzlers for chess buffs is the Knight’s Tour
 * problem. The question is this: Can the chess piece called the knight move
 * around an empty chessboard and touch each of the 64 squares once and only
 * once? We study this intriguing problem in depth in this exercise.
 *
 * The knight makes L-shaped moves (over two in one direction then over one in
 * a perpendicular direction). Thus, from a square in the middle of an empty
 * chessboard, the knight can make eight different moves (numbered 0 through 7)
 * as shown in Fig. 7.25.
 *
 * A.
 * Draw an 8-by-8 chessboard on a sheet of paper and attempt a Knight’s Tour by
 * hand. Put a 1 in the first square you move to, a 2 in the second square, a 3
 * in the third, etc. Before starting the tour, estimate how far you think
 * you’ll get, remembering that a full tour consists of 64 moves. How far did
 * you get? Was this close to your estimate?
 *
 * B.
 * Now let’s develop a program that will move the knight around a chessboard.
 * The board is represented by an 8-by-8 two-dimensional array board. Each of
 * the squares is initialized to zero. We describe each of the eight possible
 * moves in terms of both their horizontal and vertical components. For
 * example, a move of type 0, as shown in Fig. 7.25, consists of moving two
 * squares horizontally to the right and one square vertically upward. Move 2
 * consists of moving one square horizontally to the left and two squares
 * vertically upward. Horizontal moves to the left and vertical moves upward
 * are indicated with negative numbers. The eight moves may be described by two
 * one-dimensional arrays, horizontal and vertical, as follows:
 *
 * horizontal[0] = 2     vertical[0] = -1
 * horizontal[1] = 1     vertical[1] = -2
 * horizontal[2] = -1    vertical[2] = -2
 * horizontal[3] = -2    vertical[3] = -1
 * horizontal[4] = -2    vertical[4] = 1
 * horizontal[5] = -1    vertical[5] = 2
 * horizontal[6] = 1     vertical[6] = 2
 * horizontal[7] = 2     vertical[7] = 1
 *
 *                   2 1
 *                  3   0
 *                    K
 *                  4   7
 *                   5 6
 *
 * Fig. 7.25 The eight possible moves of the knight
 *
 * Let the variables currentRow and currentColumn indicate the row and column
 * of the knight’s current position. To make a move of type moveNumber, where
 * moveNumber is between 0 and 7, your program uses the statements
 *
 * currentRow += vertical[moveNumber];
 * currentColumn += horizontal[moveNumber];
 *
 * Keep a counter that varies from 1 to 64. Record the latest count in each
 * square the knight moves to. Remember to test each potential move to see if
 * the knight has already visited that square, and, of course, test every
 * potential move to make sure that the knight does not land off the
 * chessboard. Now write a program to move the knight around the chessboard.
 * Run the program. How many moves did the knight make?
 *
 * C.
 * After attempting to write and run a Knight’s Tour program, you’ve probably
 * developed some valuable insights. We’ll use these to develop a heuristic (or
 * strategy) for moving the knight. Heuristics do not guarantee success, but a
 * carefully developed heuristic greatly improves the chance of success. You
 * may have observed that the outer squares are more troublesome than the
 * squares nearer the center of the board. In fact, the most troublesome, or
 * inaccessible, squares are the four corners.
 *
 * Intuition may suggest that you should attempt to move the knight to the most
 * troublesome squares first and leave open those that are easiest to get to,
 * so when the board gets congested near the end of the tour, there will be a
 * greater chance of success.
 *
 * We may develop an “accessibility heuristic” by classifying each square
 * according to how accessible it’s then always moving the knight to the square
 * (within the knight’s L-shaped moves, of course) that’s least accessible. We
 * label a two-dimensional array accessibility with numbers indicating from how
 * many squares each particular square is accessible. On a blank chessboard,
 * each center square is rated as 8, each corner square is rated as 2 and the
 * other squares have accessibility numbers of 3, 4 or 6 as follows:
 *
 * 2 3 4 4 4 4 3 2
 * 3 4 6 6 6 6 4 3
 * 4 6 8 8 8 8 6 4
 * 4 6 8 8 8 8 6 4
 * 4 6 8 8 8 8 6 4
 * 4 6 8 8 8 8 6 4
 * 3 4 6 6 6 6 4 3
 * 2 3 4 4 4 4 3 2
 *
 * Now write a version of the Knight’s Tour program using the accessibility
 * heuristic. At any time, the knight should move to the square with the lowest
 * accessibility number. In case of a tie, the knight may move to any of the
 * tied squares. Therefore, the tour may begin in any of the four corners.
 * [Note: As the knight moves around the chessboard, your program should reduce
 * the accessibility numbers as more and more squares become occupied. In this
 * way, at any given time during the tour, each available square’s
 * accessibility number will remain equal to precisely the number of squares
 * from which that square may be reached.] Run this version of your program.
 * Did you get a full tour? Now modify the program to run 64 tours, one
 * starting from each square of the chessboard. How many full tours did you
 * get?
 *
 * D.
 * Write a version of the Knight’s Tour program which, when encountering a tie
 * between two or more squares, decides what square to choose by looking ahead
 * to those squares reachable from the “tied” squares. Your program should move
 * to the square for which the next move would arrive at a square with the
 * lowest accessibility number.
 */

#include <array>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


struct BoardPosition final
{
    int row;
    int column;
};


template<class T>
class Board
{
public:
    static constexpr int kSideLength {8};

    Board() : board_{}
    {
    }
/* =============================== Accessors =============================== */
    const T &at(const int row, const int column) const
    {
        if (row < 0 || row >= kSideLength) {
            throw out_of_range(string("'row' out of range!"));
        }
        if (column < 0 || column >= kSideLength) {
            throw out_of_range(string("'column' out of range!"));
        }
        return board_[row][column];
    }
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
    void at(const int row, const int column, const T &value)
    {
        if (row < 0 || row >= kSideLength) {
            throw out_of_range(string("'row' out of range!"));
        }
        if (column < 0 || column >= kSideLength) {
            throw out_of_range(string("'column' out of range!"));
        }
        board_[row][column] = value;
    }
/* =============================== Mutators ================================ */
protected:
    array<array<T, kSideLength>, kSideLength> board_;
};


class KnightBoard : public Board<bool>
{
public:
    static constexpr int kMaxVisits {kSideLength * kSideLength};

    /**
     * Default constructor places the 'Knight' on the upper left corner.
     */
    KnightBoard() : visits_{1}, row_{0}, column_{0}
    {
        // Mark the initial position as visited.
        at(row(), column(), true);
    }

    KnightBoard(const int initial_row, const int initial_column)
        : visits_{1}, row_{row(initial_row)}, column_{column(initial_column)}
    {
        // Mark the initial position as visited.
        at(row(), column(), true);
    }

/* =============================== Accessors =============================== */
    void DisplayStatus() const
    {
        puts("Move Number Reference");
        puts("+-+-+-+-+-+\n"
             "| |2| |1| |\n"
             "+-+-+-+-+-+\n"
             "|3| | | |0|\n"
             "+-+-+-+-+-+\n"
             "| | |K| | |\n"
             "+-+-+-+-+-+\n"
             "|4| | | |7|\n"
             "+-+-+-+-+-+\n"
             "| |5| |6| |\n"
             "+-+-+-+-+-+\n");

        puts("Board Status");
        for (decltype(board_.size()) i {0}; i < board_.size(); ++i) {
            for (decltype(board_[i].size()) t {0}; t < board_[i].size(); ++t) {
                printf("+-");
            }
            puts("+");

            for (decltype(board_[i].size()) j {0}; j < board_[i].size(); ++j) {
                if (i == static_cast<size_t>(row()) &&
                    j == static_cast<size_t>(column())) {
                    printf("|K");
                } else {
                    printf("|%s", board_[i][j] ? "*" : " ");
                }
            }
            puts("|");
        }

        for (decltype(board_[0].size()) i {0}; i < board_[0].size(); ++i) {
            printf("+-");
        }
        puts("+\n");
    }

    const int &visits() const
    {
        return visits_;
    }

    const int &row() const
    {
        return row_;
    }

    const int &column() const
    {
        return column_;
    }
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
    void MoveKnight(const BoardPosition &position)
    {
        // Could also throw 'out_of_range'.
        if (at(row() + position.row, column() + position.column) == true) {
            throw invalid_argument(string("'position' is already visited!"));
        }

        // Update the current occupied position.
        row(row() + position.row);
        column(column() + position.column);

        // Mark it as visited.
        at(row(), column(), true);
        // Increment number of visited spot.
        visits(visits() + 1);
    }

    void visits(const int &new_visits)
    {
        if (new_visits < 1 || new_visits > kMaxVisits) {
            throw out_of_range(string("'new_visits' out of range!"));
        }
        visits_ = new_visits;
    }

    int row(const int &new_row)
    {
        if (new_row < 0 || new_row >= kSideLength) {
            throw out_of_range(string("'new_row' out of range!"));
        }
        return row_ = new_row;
    }

    int column(const int &new_column)
    {
        if (new_column < 0 || new_column >= kSideLength) {
            throw out_of_range(string("'new_column' out of range!"));
        }
        return column_ = new_column;
    }
/* =============================== Mutators ================================ */

private:
    int visits_;
    int row_;
    int column_;
};


class Knight final
{
public:
    /**
     *                   2 1
     *                  3   0
     *                    K
     *                  4   7
     *                   5 6
     */
    BoardPosition Move(int move_number)
    {
        BoardPosition position {};

        if (move_number < 0 || move_number >= KnightBoard::kSideLength) {
            throw out_of_range(string("'move_number' out of range!"));
        }

        position.row = vertical_[static_cast<size_t>(move_number)];
        position.column = horizontal_[static_cast<size_t>(move_number)];

        return position;
    }
private:
    static constexpr array<int, KnightBoard::kSideLength> horizontal_ {
        {2, 1, -1, -2, -2, -1, 1, 2}
    };
    static constexpr array<int, KnightBoard::kSideLength> vertical_ {
        {-1, -2, -2, -1, 1, 2, 2, 1}
    };
};

constexpr array<int, KnightBoard::kSideLength> Knight::horizontal_;
constexpr array<int, KnightBoard::kSideLength> Knight::vertical_;

int main(void)
{
    bool initial {true};
    bool row_success {false};
    bool column_success {false};
    int move_direction {0};
    BoardPosition initial_position {};
    BoardPosition direction_position {};
    Knight knight;

    cout \
        << "To exit the program, press [Ctrl-D] on UNIX\n"
        << "or [Ctrl-Z] on Windows during input event to quit.\n";

    while (!(row_success && column_success)) {

        cout << "Enter the initial row of knight: ";
        if (cin >> initial_position.row) {
            row_success = true;
        }

        cout << "Enter the initial column of knight: ";
        if (cin >> initial_position.column) {
            column_success = true;
        }

        if (row_success && column_success) {
            try {
                KnightBoard tmp_board(initial_position.row,
                                  initial_position.column);
            } catch (out_of_range &except) {
                cerr << except.what() << endl;
                cout << "The entered position is invalid!\n";

                row_success = column_success = false;
                continue;
            }
        }
    }

    KnightBoard board(initial_position.row, initial_position.column);

    do {
        if (initial) {
            initial = false;
        } else {
            try {
                direction_position = knight.Move(move_direction);
            } catch (out_of_range &except) {
                cerr << except.what() << endl;
                cout << "Please re-enter the direction number [0-7]: ";
                continue;
            }
            try {
                board.MoveKnight(direction_position);
#ifdef PRINT_DEBUG_INFO
                cout \
                    << "Row: " << board.row() << " "
                    << "Column: " << board.column() << endl;
#endif
            } catch (out_of_range &except) {

                cerr << except.what() << endl;
                cout \
                    << "The move specified would be outside of board.\n"
                    << "Please re-enter the direction number [0-7]: ";
                continue;
            } catch (invalid_argument &except) {
                cerr << except.what() << endl;
                cout \
                    << "The move specified would visit "
                    << "an already visited location.\n"
                    << "Please re-enter the direction number [0-7]: ";
                continue;
            }
        }

        if (board.visits() == board.kMaxVisits) {
            cout << "Knight's Tour finished." << endl;
            break;
        }
        board.DisplayStatus();
        cout << "Enter the move direction number: ";
    } while (cin >> move_direction);
    return 0;
}
