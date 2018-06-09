#include <iostream>

#include "HeuristicBoard.hpp"

using namespace std;

const size_t HeuristicBoard::kAccessibilityMax {Knight::kMaxMoveNumber + 1};

/**
 * Construct a 'HeuristicBoard' object that contains initial accessibility
 * scores based on all possible moves made by 'knight' on each chessboard
 * position.
 *
 * @param knight A constant lvalue used for computing accessibility scores.
 */
HeuristicBoard::HeuristicBoard(const Knight &knight) :
    visits_{0}, complete_{false}
{
    BuildAccessibilityIndex(knight);
}
/* =============================== Accessors =============================== */
/**
 * Return the number of visited chessboard positions.
 */
ptrdiff_t HeuristicBoard::visits() const
{
    return visits_;
}

/**
 * Return whether all the chessboard positions are visited.
 */
bool HeuristicBoard::complete() const
{
    return complete_;
}

/**
 * Display the accessibility score for each chessboard position.
 *
 * @see KnightBoard::DisplayStatus
 */
void HeuristicBoard::DisplayStatus() const
{
    auto cout_repeat = [](const string &pattern, const size_t count) {
        for (size_t z {0}; z < count; ++z) {
            cout << pattern;
        }
    };

    cout << "Heuristic Board Status" "\n";

    // Display all the column indexes above the top of the board.
    cout << " ";
    for (size_t j {0}; j < board_[0].size(); ++j) {
        cout << " " << j;
    }
    cout << "\n";

    for (size_t i {0}; i < board_.size(); ++i) {
        cout << " ";
        cout_repeat("+-"s, board_[i].size());
        cout \
            << "+" "\n"
            << i;
        for (size_t j {0}; j < board_[i].size(); ++j) {
            cout << "|" << board_[i][j];
        }
        cout << "|" << i << "\n";
    }
    cout << " ";
    cout_repeat("+-"s, board_[0].size());
    cout << "+" "\n";

    // Display all the column indexes below the bottom of the board.
    cout << " ";
    for (size_t j {0}; j < board_[0].size(); ++j) {
        cout << " " << j;
    }

    cout << endl;
}
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
/**
 * Compute initial accessibility scores based on all possible moves made by
 * 'knight' on each chessboard position.
 *
 * @param knight A constant lvalue used for computing accessibility scores.
 */
void HeuristicBoard::BuildAccessibilityIndex(const Knight &knight)
{
    decltype(knight.Move(0)) position {};
    ptrdiff_t new_row, new_column;
    size_t accessibility_score;

    ClearAccessibilityIndex();
    // For each possible board position.
    for (size_t i {0}; i < board_.size(); ++i) {
        for (size_t j {0}; j < board_[i].size(); ++j) {
            // For each possible move direction of 'Knight'.
            for (size_t k {0}; k <= Knight::kMaxMoveNumber; ++k) {
                position = knight.Move(k);
                try {
                    new_row = static_cast<ptrdiff_t>(i);
                    new_column = static_cast<ptrdiff_t>(j);

                    // Test position accessibility.
                    at(new_row + position.row,
                       new_column + position.column);
                    // Retrieve current accessibility score.
                    accessibility_score = at(new_row, new_column) + 1;
                    // Store the updated accessibility score.
                    at(new_row, new_column, accessibility_score);
                } catch (out_of_range &except) {
                    // Skip the current move direction should the move make
                    // the 'Knight' piece lie out of board.
                    ;
                }
            }
        }
    }
}

/**
 * Reset all accessibility scores, visited chessboard positions, and
 * complete state.
 */
void HeuristicBoard::ClearAccessibilityIndex()
{
    for (ptrdiff_t i {0}; i < HeuristicBoard::kSideLength; ++i) {
        for (ptrdiff_t j {0}; j < HeuristicBoard::kSideLength; ++j) {
            at(i, j, 0);
        }
    }
    visits(0);
    complete(false);
}

/**
 * For the current board 'position', probe and return the move number
 * associated with the lowest accessibility score reachable from 'position'
 * that is not zero.
 *
 * @param position Constant lvalue reference of current knight position.
 * @param knight Constant lvalue reference of a 'Knight' object.
 * @throw std::range_error Upon reaching a dead end where no move exists.
 * @return The move number with the minimum accessibility score.
 */
size_t HeuristicBoard::ProbeNextMoveNumber(const BoardPosition &position,
                                           const Knight &knight) const
{
    decltype(knight.Move(0)) offset {};
    ptrdiff_t new_row, new_column;
    size_t accessibility_score, result_move_number;
    size_t lowest_accessibility {Knight::kMaxMoveNumber + 2};

    for (size_t i {0}; i <= Knight::kMaxMoveNumber; ++i) {
        offset = knight.Move(i);
        try {
            new_row = position.row + offset.row;
            new_column = position.column + offset.column;

            accessibility_score = at(new_row, new_column);

            if (accessibility_score < lowest_accessibility &&
                0 != accessibility_score) {
                lowest_accessibility = accessibility_score;
                result_move_number = i;
            }
        } catch (out_of_range &except) {
            ;
        }
    }

    // The heuristic should come to a stop should there is not a single
    // possible move of knight; in other words, all the positions reachable
    // have an accessibility score of zero.
    if (Knight::kMaxMoveNumber + 2 == lowest_accessibility) {
        throw range_error("Knight piece reached a dead end!"s);
    }
    return result_move_number;
}

/**
 * For the 'position' that is to be visited, update all the accessibility
 * scores reachable from the 'position' by 'knight'.
 *
 * @param position Constant lvalue reference of current knight position.
 * @param knight Constant lvalue reference of a 'Knight' object.
 */
void HeuristicBoard::UpdateAccessibilityIndex(const BoardPosition &position,
                                              const Knight &knight)
{
    decltype(knight.Move(0)) offset {};
    ptrdiff_t new_row, new_column;
    size_t accessibility_score;

    // Corner Case:
    // When the tour is about to finish, the remaining two unvisited
    // 'position's need to be kept intact; otherwise the tour would reach
    // a "dead end".
    if (KnightBoard::kMaxVisits == visits() + 2 ||
        KnightBoard::kMaxVisits == visits() + 1) {
        at(position.row, position.column, 0);
        visits(visits() + 1);
        return;
    }

    // For all the positions reachable from the current 'position' by
    // 'knight', decrease their accessibility score by one since the
    // current 'position' is to be visited.
    for (size_t i {0}; i <= Knight::kMaxMoveNumber; ++i) {
        offset = knight.Move(i);
        try {
            new_row = position.row + offset.row;
            new_column = position.column + offset.column;

            // Test position accessibility.
            accessibility_score = at(new_row, new_column);

            if (accessibility_score >= 1) {
                --accessibility_score;
            }

            at(new_row, new_column, accessibility_score);
        } catch (out_of_range &except) {
            // Do not do anything if the move lies outside of board.
            ;
        }
    }
    // Mark the current position as unreachable.
    at(position.row, position.column, 0);

    if (KnightBoard::kMaxVisits == visits()) {
        complete(true);
    } else {
        visits(visits() + 1);
    }
}

/* =============================== Mutators ================================ */

/**
 * Set the number of visited chessboard positions.
 *
 * @param new_visits New number of visited chessboard positions.
 * @throw std::out_of_range
 * @return New number of visited chessboard positions.
 */
ptrdiff_t HeuristicBoard::visits(const ptrdiff_t new_visits)
{
    if (new_visits < 0 || new_visits > KnightBoard::kMaxVisits) {
        throw out_of_range("'new_visits' out of range!"s);
    }
    return visits_ = new_visits;
}

/**
 * Set whether all the chessboard positions are visited.
 *
 * @param new_complete Whether all the chessboard positions are visited.
 * @return Whether all the chessboard positions are visited.
 */
bool HeuristicBoard::complete(const bool new_complete)
{
    return complete_ = new_complete;
}
