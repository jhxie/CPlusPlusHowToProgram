#include <iostream>
#include <thread>

#include "EventLoop.hpp"
#include "HeuristicBoard.hpp"
#include "KnightBoard.hpp"

using namespace std;

/**
 * Given the initial knight's 'start' position, return a pointer to a list
 * containing valid direction numbers determined by accessibility heuristics.
 *
 * @param start The constant lvalue reference to initial chessboard position.
 * @param halt_duration Number of seconds before next move is made.
 * @return A pointer to a list containing valid direction numbers.
 */
KnightMoveListPointer
KnightMoveHeuristicEventLoop(const BoardPosition &start,
                             const chrono::seconds &halt_duration)
{
    size_t move_direction {0};
    BoardPosition position {start};
    BoardPosition offset;
    Knight knight;
    KnightBoard board(start.row, start.column);
    HeuristicBoard heuristic_board(knight);
    KnightMoveListPointer direction_list_pointer {
        new list<size_t>
    };
    heuristic_board.UpdateAccessibilityIndex(position, knight);

    while (false == board.complete()) {
        board.DisplayStatus();
#ifdef PRINT_DEBUG_INFO
        heuristic_board.DisplayStatus();
#endif
        this_thread::sleep_for(halt_duration);
        try {
            move_direction = heuristic_board.ProbeNextMoveNumber(position,
                                                                 knight);
            direction_list_pointer->push_back(move_direction);
            offset = knight.Move(move_direction);
            position.row += offset.row;
            position.column += offset.column;
            board.MoveKnight(move_direction, knight);
            heuristic_board.UpdateAccessibilityIndex(position, knight);
        } catch (range_error &except) {
            break;
        }
    }

    if (board.complete()) {
        cout << "Knight's Tour finished." << endl;
        board.DisplayStatus();
#ifdef PRINT_DEBUG_INFO
        heuristic_board.DisplayStatus();
#endif
    }

    return direction_list_pointer;
}

/**
 * Given the initial knight's 'start' position, return whether the tour fully
 * completes based on accessibility heuristics.
 *
 * @param start The constant lvalue reference to initial chessboard position.
 * @return Whether the heuristics completes the tour for 'start' position.
 */
bool
KnightMoveBatchHeuristicEventLoop(const BoardPosition &start)
{
    size_t move_direction {0};
    BoardPosition position {start};
    BoardPosition offset;
    Knight knight;
    KnightBoard board(start.row, start.column);
    HeuristicBoard heuristic_board(knight);
    heuristic_board.UpdateAccessibilityIndex(position, knight);

    while (false == board.complete()) {
        try {
            move_direction = heuristic_board.ProbeNextMoveNumber(position,
                                                                 knight);
            offset = knight.Move(move_direction);
            position.row += offset.row;
            position.column += offset.column;
            board.MoveKnight(move_direction, knight);
            heuristic_board.UpdateAccessibilityIndex(position, knight);
        } catch (range_error &except) {
            break;
        }
    }

    return board.complete();
}

/**
 * Given the knight's initial 'start' position and direction numbers in
 * 'direction_list', the current status of chessboard would be shown for
 * 'halt_duration' number of seconds, one step at a time.
 *
 * @param start The constant lvalue reference to initial chessboard position.
 * @param direction_list A constant list reference with direction numbers.
 * @param halt_duration Number of seconds before next move is made.
 */
void
KnightMoveReplayEventLoop(const BoardPosition &start,
                          const list<size_t> &direction_list,
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
            board.MoveKnight(move_direction, knight);
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
