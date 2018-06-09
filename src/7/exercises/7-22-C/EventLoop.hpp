#pragma once

#include <chrono>
#include <cstddef>
#include <list>
#include <memory>

#include "Board.hpp"

using KnightMoveListPointer = std::unique_ptr<std::list<size_t>>;

KnightMoveListPointer
KnightMoveHeuristicEventLoop(const BoardPosition &start,
                             const std::chrono::seconds &halt_duration);

bool
KnightMoveBatchHeuristicEventLoop(const BoardPosition &start);

void
KnightMoveReplayEventLoop(const BoardPosition &start,
                          const std::list<size_t> &direction_list,
                          const std::chrono::seconds &halt_duration);
