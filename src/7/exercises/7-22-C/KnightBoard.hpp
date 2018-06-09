#pragma once

#include <array>
#include <cstddef>

#include "Board.hpp"

class Knight final
{
public:
    static const size_t kMaxMoveNumber;

    static BoardPosition Move(const size_t move_number);
private:
    static const std::array<ptrdiff_t, Board<bool>::kSideLength> horizontal_;
    static const std::array<ptrdiff_t, Board<bool>::kSideLength> vertical_;
};

class KnightBoard : public Board<bool>
{
public:
    static const ptrdiff_t kMaxVisits;

    KnightBoard();

    KnightBoard(const ptrdiff_t initial_row, const ptrdiff_t initial_column);

/* =============================== Accessors =============================== */
    void DisplayStatus() const;

    ptrdiff_t visits() const;

    ptrdiff_t row() const;

    ptrdiff_t column() const;

    bool complete() const;
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
    void MoveKnight(const size_t move_number, const Knight &knight);
/* =============================== Mutators ================================ */

private:
/* =============================== Mutators ================================ */
    ptrdiff_t visits(const ptrdiff_t new_visits);

    ptrdiff_t row(const ptrdiff_t new_row);

    ptrdiff_t column(const ptrdiff_t new_column);

    bool complete(const bool new_complete);
/* =============================== Mutators ================================ */

    ptrdiff_t visits_;
    ptrdiff_t row_;
    ptrdiff_t column_;
    bool complete_;
};
