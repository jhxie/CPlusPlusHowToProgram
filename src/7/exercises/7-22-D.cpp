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
 * D.
 * Write a version of the Knight’s Tour program which, when encountering a tie
 * between two or more squares, decides what square to choose by looking ahead
 * to those squares reachable from the “tied” squares. Your program should move
 * to the square for which the next move would arrive at a square with the
 * lowest accessibility number.
 */

#include <array>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>

using namespace std;
using KnightMoveListPointer = unique_ptr<list<size_t>>;


struct BoardPosition final
{
    ptrdiff_t row;
    ptrdiff_t column;
};


template<class T>
class Board
{
public:
    static constexpr ptrdiff_t kSideLength {8};

    Board() : board_{}
    {
    }
/* =============================== Accessors =============================== */
    /**
     * Return an lvalue reference of type 'T' that is stored at 'row' and
     * 'column' index.
     *
     * @param row The row index.
     * @param column The column index.
     * @throw std::out_of_range
     * @return An lvalue reference of type 'T'.
     */
    const T &at(const ptrdiff_t row, const ptrdiff_t column) const
    {
        if (row < 0 || row >= kSideLength) {
            throw out_of_range("'row' out of range!"s);
        }
        if (column < 0 || column >= kSideLength) {
            throw out_of_range("'column' out of range!"s);
        }
        return board_[row][column];
    }
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
    /**
     * Store a copy of type 'T' at 'row' and 'column' index.
     *
     * @param row The row index.
     * @param column The column index.
     * @param value The lvalue reference to the content to be stored.
     * @throw std::out_of_range
     */
    void at(const ptrdiff_t row, const ptrdiff_t column, const T &value)
    {
        if (row < 0 || row >= kSideLength) {
            throw out_of_range("'row' out of range!"s);
        }
        if (column < 0 || column >= kSideLength) {
            throw out_of_range("'column' out of range!"s);
        }
        board_[row][column] = value;
    }
/* =============================== Mutators ================================ */
protected:
    array<array<T, kSideLength>, kSideLength> board_;
};


class Knight final
{
public:
    static constexpr size_t kMaxMoveNumber {7};
    /**
     * Use the current 'move_number' to generate a move direction offset.
     *
     * @param move_number A move number that is in range [0, kMaxMoveNumber].
     * @throw std::out_of_range
     * @return Chessboard offset that corresponds to move direction.
     * @see BoardPosition
     * @see Knight::kMaxMoveNumber
     *
     *                   2 1
     *                  3   0
     *                    K
     *                  4   7
     *                   5 6
     */
    static BoardPosition Move(const size_t move_number)
    {
        BoardPosition position {};

        if (move_number > kMaxMoveNumber) {
            throw out_of_range("'move_number' out of range!"s);
        }

        position.row = vertical_[move_number];
        position.column = horizontal_[move_number];

        return position;
    }
private:
    static constexpr array<ptrdiff_t, Board<bool>::kSideLength> horizontal_ {
        {2, 1, -1, -2, -2, -1, 1, 2}
    };
    static constexpr array<ptrdiff_t, Board<bool>::kSideLength> vertical_ {
        {-1, -2, -2, -1, 1, 2, 2, 1}
    };
};

constexpr array<ptrdiff_t, Board<bool>::kSideLength> Knight::horizontal_;
constexpr array<ptrdiff_t, Board<bool>::kSideLength> Knight::vertical_;


class KnightBoard : public Board<bool>
{
public:
    static constexpr ptrdiff_t kMaxVisits {kSideLength * kSideLength};

    /**
     * Default constructor places the 'Knight' on the upper left corner.
     */
    KnightBoard() : visits_{1}, row_{0}, column_{0}, complete_{false}
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
    KnightBoard(const ptrdiff_t initial_row, const ptrdiff_t initial_column) :
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
    void DisplayStatus() const
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
    ptrdiff_t visits() const
    {
        return visits_;
    }

    /**
     * Return the current 'row' index of occupied chessboard position.
     */
    ptrdiff_t row() const
    {
        return row_;
    }

    /**
     * Return the current 'column' index of occupied chessboard position.
     */
    ptrdiff_t column() const
    {
        return column_;
    }

    /**
     * Return whether all the chessboard positions are visited.
     */
    bool complete() const
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
    void MoveKnight(const size_t move_number, const Knight &knight)
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

private:
/* =============================== Mutators ================================ */
    /**
     * Set the number of visited chessboard positions.
     *
     * @param new_visits New number of visited chessboard positions.
     * @throw std::out_of_range
     * @return New number of visited chessboard positions.
     */
    ptrdiff_t visits(const ptrdiff_t new_visits)
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
    ptrdiff_t row(const ptrdiff_t new_row)
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
    ptrdiff_t column(const ptrdiff_t new_column)
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
    bool complete(const bool new_complete)
    {
        return complete_ = new_complete;
    }
/* =============================== Mutators ================================ */

    ptrdiff_t visits_;
    ptrdiff_t row_;
    ptrdiff_t column_;
    bool complete_;
};


class HeuristicBoard : public Board<size_t>
{
public:
    static constexpr size_t kAccessibilityMax {Knight::kMaxMoveNumber + 1};

    /**
     * Construct a 'HeuristicBoard' object that contains initial accessibility
     * scores based on all possible moves made by 'knight' on each chessboard
     * position.
     *
     * @param knight A constant lvalue used for computing accessibility scores.
     */
    HeuristicBoard(const Knight &knight) : visits_{0}, complete_{false}
    {
        BuildAccessibilityIndex(knight);
    }
/* =============================== Accessors =============================== */
    /**
     * Return the number of visited chessboard positions.
     */
    ptrdiff_t visits() const
    {
        return visits_;
    }

    /**
     * Return whether all the chessboard positions are visited.
     */
    bool complete() const
    {
        return complete_;
    }

    /**
     * Display the accessibility score for each chessboard position.
     *
     * @see KnightBoard::DisplayStatus
     */
    void DisplayStatus() const
    {
        auto cout_repeat = [](const string &pattern, const size_t count) {
            for (size_t z {0}; z < count; ++z) {
                cout << pattern;
            }
        };

        cout << "Heuristic Board Status" "\n";

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
    void BuildAccessibilityIndex(const Knight &knight)
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
    void ClearAccessibilityIndex()
    {
        for (size_t i {0}; i < board_.size(); ++i) {
            for (size_t j {0}; j < board_[i].size(); ++j) {
                board_[i][j] = 0;
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
     * In case of a tie among two or more reachable 'position's, look ahead
     * from the tied 'position's recursively.
     *
     * @param position Constant lvalue reference of current knight position.
     * @param knight Constant lvalue reference of a 'Knight' object.
     * @throw std::range_error Upon reaching a dead end where no move exists.
     * @return The move number with the minimum accessibility score.
     */
    size_t ProbeNextMoveNumber(const BoardPosition &position,
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
    void UpdateAccessibilityIndex(const BoardPosition &position,
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
private:
    /**
     * Set the number of visited chessboard positions.
     *
     * @param new_visits New number of visited chessboard positions.
     * @throw std::out_of_range
     * @return New number of visited chessboard positions.
     */
    ptrdiff_t visits(const ptrdiff_t new_visits)
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
    bool complete(const bool new_complete)
    {
        return complete_ = new_complete;
    }

    ptrdiff_t visits_;
    bool complete_;
};


/**
 * Given the initial knight's 'start' position, return a pointer to a list
 * containing valid direction numbers determined by accessibility heuristics.
 *
 * @param start The constant lvalue reference to initial chessboard position.
 * @param halt_duration Number of seconds before next move is made.
 * @return A pointer to a list containing valid direction numbers.
 */
static KnightMoveListPointer
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
 * Given the knight's initial 'start' position and direction numbers in
 * 'direction_list', the current status of chessboard would be shown for
 * 'halt_duration' number of seconds, one step at a time.
 *
 * @param start The constant lvalue reference to initial chessboard position.
 * @param direction_list A constant list reference with direction numbers.
 * @param halt_duration Number of seconds before next move is made.
 */
static void
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
