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
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
 #include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

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
    KnightBoard() : visits_{1}, row_{0}, column_{0}, complete_{false}
    {
        // Mark the initial position as visited.
        at(row(), column(), true);
    }

    KnightBoard(const int initial_row, const int initial_column) :
        visits_{1},
        row_{row(initial_row)},
        column_{column(initial_column)},
        complete_{false}
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
        printf("Visit Summary: %d/%d visited.\n", visits(), kMaxVisits);
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

    const bool &complete() const
    {
        return complete_;
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

        if (visits() == kMaxVisits) {
            complete(true);
        }
    }
/* =============================== Mutators ================================ */

private:
/* =============================== Mutators ================================ */
    int visits(const int &new_visits)
    {
        if (new_visits < 1 || new_visits > kMaxVisits) {
            throw out_of_range(string("'new_visits' out of range!"));
        }
        return visits_ = new_visits;
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

    bool complete(const bool &new_complete)
    {
        return complete_ = new_complete;
    }
/* =============================== Mutators ================================ */

    int visits_;
    int row_;
    int column_;
    bool complete_;
};


class Knight final
{
public:
    static constexpr int kMaxMoveNumber {7};
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

        if (move_number < 0 || move_number > kMaxMoveNumber) {
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

using KnightMoveListPointer = unique_ptr<list<int>>;

static KnightMoveListPointer
KnightMoveInteractiveEventLoop(const BoardPosition &start)
{
    bool initial {true};
    int move_direction {0};
    BoardPosition direction_position {};
    Knight knight;
    KnightBoard board(start.row, start.column);
    KnightMoveListPointer direction_list_pointer {
        new list<int>
    };

    do {
        if (initial) {
            initial = false;
        } else {
            try {
                direction_position = knight.Move(move_direction);
            } catch (out_of_range &except) {
                cerr << except.what() << endl;
                cout \
                    << "Please re-enter the direction number [0-"
                    << Knight::kMaxMoveNumber
                    << "]: ";
                continue;
            }
            try {
                cout \
                    << "Knight Destination Position:\n"
                    << "Row: " << board.row() + direction_position.row << "\n"
                    << "Column: " << board.column() + direction_position.column
                    << endl;
                board.MoveKnight(direction_position);
                // At this point 'move_direction' must be valid.
                direction_list_pointer->push_back(move_direction);
            } catch (out_of_range &except) {

                cerr << except.what() << endl;
                cout \
                    << "The move specified would land outside of board.\n"
                    << "Please re-enter the direction number [0-"
                    << Knight::kMaxMoveNumber
                    << "]: ";
                continue;
            } catch (invalid_argument &except) {
                cerr << except.what() << endl;
                cout \
                    << "The move specified would visit "
                    << "an already visited location.\n"
                    << "Please re-enter the direction number [0-"
                    << Knight::kMaxMoveNumber
                    << "]: ";
                continue;
            }
        }

        if (board.complete()) {
            cout << "Knight's Tour finished." << endl;
            break;
        }
        board.DisplayStatus();
        cout << "Enter the move direction number: ";
    } while (cin >> move_direction);

    return direction_list_pointer;
}

static void StartInteractiveMode(const char *const output_file_name = nullptr)
{
    bool row_success {false};
    bool column_success {false};
    bool write_summary_file {false};
    BoardPosition initial_position {};
    ofstream output_file_stream;

    output_file_stream.open(output_file_name);
    if (output_file_stream.good()) {
        cout << "The output file is [" << output_file_name << "]" << "\n\n";
        write_summary_file = true;
    }

    cout << "\n" "Enter the initial row of knight: ";
    if (cin >> initial_position.row) {
        row_success = true;
    }

    cout << "\n" "Enter the initial column of knight: ";
    if (cin >> initial_position.column) {
        column_success = true;
    }

    if (row_success && column_success) {
        try {
            KnightBoard tmp_board(initial_position.row,
                              initial_position.column);
        } catch (out_of_range &except) {
            cerr << except.what() << endl;
            cout << "\n" "The entered position is invalid!\n";
            row_success = column_success = false;
            exit(EXIT_FAILURE);
        }
    } else {
            cout << "\n" "Position is not properly entered!\n";
            row_success = column_success = false;
            exit(EXIT_FAILURE);
    }

    KnightMoveListPointer direction_list_pointer {
        KnightMoveInteractiveEventLoop(initial_position)
    };

    if (write_summary_file) {
        output_file_stream \
            << initial_position.row << "\t"
            << initial_position.column << "\n";

        for (auto const &direction : *direction_list_pointer) {
            output_file_stream << direction << "\n";
        }
    }
}

static void
KnightMoveReplayEventLoop(const BoardPosition &start,
                          const list<int> &direction_list,
                          const chrono::seconds &halt_duration)
{
    BoardPosition direction_position {};
    Knight knight;
    KnightBoard board(start.row, start.column);

    for (auto const &move_direction : direction_list) {
        try {
            direction_position = knight.Move(move_direction);
        } catch (out_of_range &except) {
            cerr << except.what() << endl;
            exit(EXIT_FAILURE);
        }
        try {
            cout \
                << "Knight Destination Position:\n"
                << "Row: " << board.row() + direction_position.row << "\n"
                << "Column: " << board.column() + direction_position.column
                << endl;
            board.MoveKnight(direction_position);
        } catch (out_of_range &except) {

            cerr << except.what() << endl;
            cout \
                << "The move specified would be outside of board.\n";
            exit(EXIT_FAILURE);
        } catch (invalid_argument &except) {
            cerr << except.what() << endl;
            cout \
                << "The move specified would visit "
                << "an already visited location.\n";
            exit(EXIT_FAILURE);
        }
        if (board.complete()) {
            cout << "Knight's Tour finished." << endl;
            break;
        }
        board.DisplayStatus();
        this_thread::sleep_for(halt_duration);
    }
}

static void StartReplayMode(const char *const input_file_name,
                            const chrono::seconds &halt_duration)
{
    bool row_success {false};
    bool column_success {false};
    int move_number {0};
    BoardPosition initial_position {};
    ifstream input_file_stream;
    list<int> direction_list;

    input_file_stream.open(input_file_name);
    if (input_file_stream.good()) {
        cout << "The input file is [" << input_file_name << "]" << "\n\n";
    } else {
        cout << "The input file for some reason is not accessible!\n";
        exit(EXIT_FAILURE);
    }

    if (input_file_stream >> initial_position.row) {
        row_success = true;
    }

    if (input_file_stream >> initial_position.column) {
        column_success = true;
    }

    if (row_success && column_success) {
        try {
            KnightBoard tmp_board(initial_position.row,
                              initial_position.column);
        } catch (out_of_range &except) {
            cerr << except.what() << endl;
            cout << "\n" "The entered position is invalid!\n";
            row_success = column_success = false;
            exit(EXIT_FAILURE);
        }
    } else {
            cout << "\n" "Initial position is not properly formatted!\n";
            row_success = column_success = false;
            exit(EXIT_FAILURE);
    }

    while (input_file_stream >> move_number) {
        direction_list.push_back(move_number);
    }

    KnightMoveReplayEventLoop(initial_position, direction_list, halt_duration);
}

int main(int argc, char *argv[])
{
    int candidate_seconds {
        6
    };
    const chrono::seconds kDefaultHaltSeconds {
        candidate_seconds
    };

    static const char *const kInvalidFlagWarning {
        "The command flag is invalid!\n"
    };
    static const char *const kHaltFlag {
        "-t"
    };
    static const char *const kHelpFlag {
        "-h"
    };
    static const char *const kInputFlag {
        "-i"
    };
    static const char *const kOutputFlag {
        "-o"
    };
    static stringstream kUsage;

    kUsage \
        << "Knight's Tour Interactive Program.\n"
        << "To record the direction(s) taken during the process,\n"
        << "specify the output file as the argument; for example:\n"
        << argv[0] << " " << kOutputFlag << " [output.txt]\n\n"
        << "To take the tour using the previously recorded output,\n"
        << "specify the input file as the argument; for example:\n"
        << argv[0] << " " << kInputFlag << " [input.txt]\n"
        << "Optionally a halt duration in seconds can be specified\n"
        << "when " << kInputFlag << " is given; for example:\n"
        << argv[0] << " " << kInputFlag << " [input.txt] "
        << kHaltFlag << " 2\n\n"
        << "If no argument is given, the program would proceed as normal.\n\n"
        << "To exit the program, press [Ctrl-D] on UNIX\n"
        << "or [Ctrl-Z] on Windows during input event to quit.\n\n" << flush;

    switch (argc) {
    // Normal mode of operation; no files are involved.
    case 1:
        StartInteractiveMode();
        break;
    // Show usage information.
    case 2:
        if (string(argv[1]) == kHelpFlag) {
            cout << kUsage.str() << flush;
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        }
        break;
    // Determine whether it is record or replay mode.
    case 3:
        if (string(argv[1]) == kOutputFlag) {
            StartInteractiveMode(argv[2]);
        } else if (string(argv[1]) == kInputFlag) {
            StartReplayMode(argv[2], kDefaultHaltSeconds);
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        }
        break;
    // Determine what is the halt duration for replay mode.
    case 5:
        if (string(argv[1]) == kInputFlag && string(argv[3]) == kHaltFlag) {
            // No attempt has been made to recover from conversion error.
            try {
                chrono::seconds custom_halt_seconds {
                    stoi(argv[4])
                };
                StartReplayMode(argv[2], custom_halt_seconds);
            } catch (invalid_argument &except) {
                cerr << except.what() << endl;
                cout << kInvalidFlagWarning;
                exit(EXIT_FAILURE);
            } catch (out_of_range &except) {
                cerr << except.what() << endl;
                cout << kInvalidFlagWarning;
                exit(EXIT_FAILURE);
            }
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        };
        break;
    default:
        cout << kInvalidFlagWarning;
        exit(EXIT_FAILURE);
    }

    return 0;
}
