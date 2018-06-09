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
 *                   2 1
 *                  3   0
 *                    K
 *                  4   7
 *                   5 6
 *
 * Fig. 7.25 The eight possible moves of the knight
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

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include "Board.hpp"
#include "EventLoop.hpp"
#include "KnightBoard.hpp"

using namespace std;


/**
 * Launch the Knight's Tour chessboard game and write the given valid initial
 * position in addition to probed valid direction numbers to the file named
 * 'output_file_name', the current status of chessboard would be
 * shown for 'halt_duration' number of seconds, one step at a time.
 *
 * @param output_file_name Constant reference of an output file name string.
 * @param halt_duration Number of seconds before next move is made.
 */
static void StartHeuristicMode(const string &output_file_name,
                               const chrono::seconds &halt_duration)
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
        KnightMoveHeuristicEventLoop(initial_position, halt_duration)
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

/**
 * Launch the batch variant of Knight's Tour Heuristics and write the
 * completion status (whether the tour finishes) for each chessboard position
 * to the file named 'output_file_name'.
 *
 * @param output_file_name Constant reference of an output file name string.
 */
static void StartBatchHeuristicMode(const string &output_file_name)
{
    bool tour_success {false};
    bool write_summary_file {false};
    BoardPosition initial_position {};
    ofstream output_file_stream;
    size_t success_count {0};
    size_t fail_count {0};

    output_file_stream.open(output_file_name);
    if (output_file_stream.good()) {
        cout << "The output file is [" << output_file_name << "]" << "\n\n";
        write_summary_file = true;
    }

    if (write_summary_file) {
        output_file_stream << "Row" "\t" "Column" "\t" "Completed" "\n";
    }

    for (ptrdiff_t i {0}; i < KnightBoard::kSideLength; ++i) {
        for (ptrdiff_t j {0}; j < KnightBoard::kSideLength; ++j) {
            initial_position.row = i;
            initial_position.column = j;
            tour_success = KnightMoveBatchHeuristicEventLoop(initial_position);

            if (tour_success) {
                ++success_count;
            } else {
                ++fail_count;
            }

            if (write_summary_file) {
                output_file_stream \
                    << i << "\t" << j << "\t" << tour_success << "\n";
            }
        }
    }

    cout \
        << "Number of completed Knight's Tours: " << success_count << "\n"
        << "Number of failed Knight's Tours: " << fail_count << endl;
}

/**
 * Launch the previously recorded Knight's Tour chessboard game from the moves
 * specified in 'output_file_name', the current status of chessboard would be
 * shown for 'halt_duration' number of seconds, one step at a time.
 *
 * @param output_file_name Constant reference of an input file name string.
 * @param halt_duration Number of seconds before next move is made.
 */
static void StartReplayMode(const string &input_file_name,
                            const chrono::seconds &halt_duration)
{
    bool row_success {false};
    bool column_success {false};
    size_t move_number {0};
    BoardPosition initial_position {};
    ifstream input_file_stream;
    list<size_t> direction_list;

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
    int halt_seconds {
        6
    };
    stringstream usage_stream;
    unordered_map<size_t, string> argument_map;

    static const chrono::seconds kDefaultHaltSeconds {
        halt_seconds
    };

    static const string kInvalidFlagWarning {
        "The command flag is invalid!\n"
    };
    static const string kHaltFlag {
        "-t"
    };
    static const string kHelpFlag {
        "-h"
    };
    static const string kInputFlag {
        "-i"
    };
    static const string kInputSample {
        "[input.txt]"
    };
    static const string kOutputFlag {
        "-o"
    };
    static const string kOutputSample {
        "[output.txt]"
    };
    static const string kBatchFlag {
        "-b"
    };

    for (int i {0}; i < argc; ++i) {
        argument_map[static_cast<size_t>(i)] = string(argv[i]);
    }

    usage_stream \
        << "Knight's Tour Heuristic Program.\n"
        << "To record the direction(s) taken during the probing process,\n"
        << "specify the output file as the argument; for example:\n"
        << argv[0] << " " << kOutputFlag << " " << kOutputSample << "\n\n"
        << "To take the tour using the previously recorded output,\n"
        << "specify the input file as the argument; for example:\n"
        << argv[0] << " " << kInputFlag << " " << kInputSample << "\n\n"
        << "Optionally a halt duration in seconds can be specified\n"
        << "when " << kInputFlag << " or " << kOutputFlag << " is given;\n"
        << "for example "
        << "(halt flag must come last, default is " << halt_seconds << "):\n"
        << argv[0] << " " << kInputFlag << " " << kInputSample << " "
        << kHaltFlag << " " << halt_seconds << "\n\n"
        << argv[0] << " " << kOutputFlag << " " << kOutputSample << " "
        << kHaltFlag << " " << halt_seconds << "\n\n"
        << "To see whether the heuristics finishes for each board position,\n"
        << "specify the batch flag after the output file; for example:\n"
        << argv[0] << " " << kOutputFlag << " " << kOutputSample << " "
        << kBatchFlag << "\n\n"
        << "If no argument is given, print the usage information.\n\n"
        << "To exit the program, press [Ctrl-D] on UNIX\n"
        << "or [Ctrl-Z] on Windows during input event to quit.\n\n"
        << flush;

    switch (argc) {
    // Print the usage information; no files are involved.
    case 1:
        cout << usage_stream.str() << flush;
        break;
    // Show usage information as requested explicitly.
    case 2:
        if (argument_map[1] == kHelpFlag) {
            cout << usage_stream.str() << flush;
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        }
        break;
    // Determine whether it is heuristic or replay mode.
    case 3:
        if (argument_map[1] == kOutputFlag) {
            StartHeuristicMode(argument_map[2], kDefaultHaltSeconds);
        } else if (argument_map[1] == kInputFlag) {
            StartReplayMode(argument_map[2], kDefaultHaltSeconds);
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        }
        break;
    // Determine whether it is batch heuristic mode.
    case 4:
        if (argument_map[3] == kBatchFlag && argument_map[1] == kOutputFlag) {
            StartBatchHeuristicMode(argument_map[2]);
        } else {
            cout << kInvalidFlagWarning;
            exit(EXIT_FAILURE);
        }
        break;
    // Determine what is the halt duration for either heuristic or replay mode.
    case 5:
        if (argument_map[3] == kHaltFlag &&
            (argument_map[1] == kOutputFlag || argument_map[1] == kInputFlag)){
            // No attempt has been made to recover from conversion error.
            try {
                chrono::seconds custom_halt_seconds {
                    stoi(argument_map[4])
                };
                if (argument_map[1] == kOutputFlag) {
                    StartHeuristicMode(argument_map[2], custom_halt_seconds);
                } else {
                    StartReplayMode(argument_map[2], custom_halt_seconds);
                }
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
    return EXIT_SUCCESS;
}
