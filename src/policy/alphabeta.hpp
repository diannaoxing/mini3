#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for minimax policy, 
 * your policy class should have get_move method
 */

class Alphabeta{
public:
  static Move get_move(State *state, int depth);
  //
};

int AB_search(State* state, int depth, int A, int B, bool maximizingPlayer);