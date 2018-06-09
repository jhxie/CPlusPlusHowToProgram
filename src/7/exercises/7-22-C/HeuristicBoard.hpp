#pragma  once

#include "Board.hpp"
#include "KnightBoard.hpp"

class HeuristicBoard : public Board<size_t>
{
public:
    static const size_t kAccessibilityMax;

    HeuristicBoard(const Knight &knight);
/* =============================== Accessors =============================== */
    ptrdiff_t visits() const;

    bool complete() const;

    void DisplayStatus() const;
/* =============================== Accessors =============================== */

/* =============================== Mutators ================================ */
    void BuildAccessibilityIndex(const Knight &knight);

    void ClearAccessibilityIndex();

    size_t ProbeNextMoveNumber(const BoardPosition &position,
                               const Knight &knight) const;

    void UpdateAccessibilityIndex(const BoardPosition &position,
                                  const Knight &knight);
/* =============================== Mutators ================================ */
private:
    ptrdiff_t visits(const ptrdiff_t new_visits);

    bool complete(const bool new_complete);

    ptrdiff_t visits_;
    bool complete_;
};
