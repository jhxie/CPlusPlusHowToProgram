#pragma once

#include <array>
#include <cstddef>
#include <stdexcept>
#include <string>


struct BoardPosition final
{
    ptrdiff_t row;
    ptrdiff_t column;
};


template<class T>
class Board
{
public:
    /**< All chessboards are of square shape with side length of 8. */
    static constexpr ptrdiff_t kSideLength {8};

    Board() : board_{}
    {
    }
/* =============================== Accessors =============================== */
    /**
     * Return a constant lvalue reference of type 'T' that is stored at 'row'
     * and 'column' index.
     *
     * @param row The row index.
     * @param column The column index.
     * @throw std::out_of_range
     * @return A constant lvalue reference of type 'T'.
     */
    const T &at(const ptrdiff_t row, const ptrdiff_t column) const
    {
        using std::out_of_range;
        using namespace std::string_literals;

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
        using std::out_of_range;
        using namespace std::string_literals;

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
    std::array<std::array<T, kSideLength>, kSideLength> board_;
};
