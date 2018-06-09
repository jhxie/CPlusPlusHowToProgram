#include <iostream>

#include "KnightBoard.hpp"

using namespace std;

const size_t Knight::kMaxMoveNumber {7};

/**
 * Use the current 'move_number' to generate a move direction offset.
 *
 * @param move_number A move number that is in range [0, kMaxMoveNumber].
 * @throw std::out_of_range
 * @return Chessboard offset that corresponds to move direction.
 * @see BoardPosition
 * @see Knight::kMaxMoveNumber
 * @see KnightBoard::DisplayStatus
 *
 * Below is a move number reference:
 *
 *                   2 1
 *                  3   0
 *                    K
 *                  4   7
 *                   5 6
 */
BoardPosition Knight::Move(const size_t move_number)
{
    BoardPosition position {};

    if (move_number > kMaxMoveNumber) {
        throw out_of_range("'move_number' out of range!"s);
    }

    position.row = vertical_[move_number];
    position.column = horizontal_[move_number];

    return position;
}

const array<ptrdiff_t, Board<bool>::kSideLength> Knight::horizontal_ {
    {2, 1, -1, -2, -2, -1, 1, 2}
};
const array<ptrdiff_t, Board<bool>::kSideLength> Knight::vertical_ {
    {-1, -2, -2, -1, 1, 2, 2, 1}
};


const ptrdiff_t KnightBoard::kMaxVisits {kSideLength * kSideLength};

/**
 * Default constructor places the 'Knight' on the upper left corner.
 */
KnightBoard::KnightBoard() :
    visits_{1},
    row_{0},
    column_{0},
    complete_{false}
{
    // Mark the initial position as visited.
    at(row(), column(), true);
}

/**
 * Construct a 'KnightBoard' object with the specified 'initial_row' and
 * 'initial_column'.
 *
 * @param initial_row The initial row index of the occupied position.
 * @param initial_column The initial column index of the occupied position.
 */
KnightBoard::KnightBoard(const ptrdiff_t initial_row,
                         const ptrdiff_t initial_column) :
    visits_{1},
    row_{row(initial_row)},
    column_{column(initial_column)},
    complete_{false}
{
    // Mark the initial position as visited.
    at(row(), column(), true);
}

/* =============================== Accessors =============================== */

/**
 * Display the current position of knight on a chessboard in addition to
 * the move number reference in 'ASCII' forms.
 */
void KnightBoard::DisplayStatus() const
{
    auto cout_repeat = [](const string &pattern, const size_t count) {
        for (size_t z {0}; z < count; ++z) {
            cout << pattern;
        }
    };

    /*
     * Note the following deliberately omits the usage of the lambda
     * defined above to enhance readability.
     */
    cout \
        << "Move Number Reference" "\n"
        << "+-+-+-+-+-+" "\n"
        << "| |2| |1| |" "\n"
        << "+-+-+-+-+-+" "\n"
        << "|3| | | |0|" "\n"
        << "+-+-+-+-+-+" "\n"
        << "| | |K| | |" "\n"
        << "+-+-+-+-+-+" "\n"
        << "|4| | | |7|" "\n"
        << "+-+-+-+-+-+" "\n"
        << "| |5| |6| |" "\n"
        << "+-+-+-+-+-+" "\n" << endl;

    cout << "Knight Board Status" "\n";

    // Display all the column indexes above the top of the board.
    cout << " ";
    for (ptrdiff_t j {0}; j < KnightBoard::kSideLength; ++j) {
        cout << " " << j;
    }
    cout << "\n";

    // Each board row consists of a border line and the board slots
    // directly below it: the slot would be shown as a 'K' should it is
    // currently occupied; otherwise it is shown either as a '*' should
    // it is previously occupied or an empty space should it is unvisited.
    for (size_t i {0}; i < board_.size(); ++i) {
        cout << " ";
        cout_repeat("+-"s, board_[i].size());
        cout \
            << "+" "\n"
            << i;
        for (size_t j {0}; j < board_[i].size(); ++j) {
            if (i == static_cast<size_t>(row()) &&
                j == static_cast<size_t>(column())) {
                cout << "|K";
            } else {
                cout << "|" << (board_[i][j] ? "*" : " ");
            }
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

    cout << "\n";
    cout \
        << "Visit Summary: "
        << visits() << "/" << kMaxVisits << " visited." << endl;
}

/**
 * Return the number of visited chessboard positions.
 */
ptrdiff_t KnightBoard::visits() const
{
    return visits_;
}

/**
 * Return the current 'row' index of occupied chessboard position.
 */
ptrdiff_t KnightBoard::row() const
{
    return row_;
}

/**
 * Return the current 'column' index of occupied chessboard position.
 */
ptrdiff_t KnightBoard::column() const
{
    return column_;
}

/**
 * Return whether all the chessboard positions are visited.
 */
bool KnightBoard::complete() const
{
    return complete_;
}
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
/**
 * Change the current position of knight on this chessboard according to
 * the direction number.
 *
 * @param move_number A move number that is in range [0, kMaxMoveNumber].
 * @param knight Constant lvalue reference of a 'Knight' object.
 * @throw std::invalid_argument
 * @see Knight::Move
 */
void KnightBoard::MoveKnight(const size_t move_number, const Knight &knight)
{
    BoardPosition position = knight.Move(move_number);
    // Could also throw 'out_of_range'.
    if (at(row() + position.row, column() + position.column) == true) {
        throw invalid_argument("'position' is already visited!"s);
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

/* =============================== Mutators ================================ */
/**
 * Set the number of visited chessboard positions.
 *
 * @param new_visits New number of visited chessboard positions.
 * @throw std::out_of_range
 * @return New number of visited chessboard positions.
 */
ptrdiff_t KnightBoard::visits(const ptrdiff_t new_visits)
{
    if (new_visits < 1 || new_visits > kMaxVisits) {
        throw out_of_range("'new_visits' out of range!"s);
    }
    return visits_ = new_visits;
}

/**
 * Set the current 'row' index of occupied chessboard position.
 *
 * @param new_row New row index of occupied chessboard position.
 * @throw std::out_of_range
 * @return New row index of occupied chessboard position.
 */
ptrdiff_t KnightBoard::row(const ptrdiff_t new_row)
{
    if (new_row < 0 || new_row >= kSideLength) {
        throw out_of_range("'new_row' out of range!"s);
    }
    return row_ = new_row;
}

/**
 * Set the current 'column' index of occupied chessboard position.
 *
 * @param new_column New column index of occupied chessboard position.
 * @throw std::out_of_range
 * @return New column index of occupied chessboard position.
 */
ptrdiff_t KnightBoard::column(const ptrdiff_t new_column)
{
    if (new_column < 0 || new_column >= kSideLength) {
        throw out_of_range("'new_column' out of range!"s);
    }
    return column_ = new_column;
}

/**
 * Set whether all the chessboard positions are visited.
 *
 * @param new_complete Whether all the chessboard positions are visited.
 * @return Whether all the chessboard positions are visited.
 */
bool KnightBoard::complete(const bool new_complete)
{
    return complete_ = new_complete;
}
/* =============================== Mutators ================================ */
