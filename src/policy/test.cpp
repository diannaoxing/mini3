#include <cstdlib>
#include "../state/state.hpp"
#include "./test.hpp"


/**
 * @brief get the best action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Test::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  // todo: use evaluate function to determine which action to choose
  Move best_action;
  int best_value = -2147483648;

  for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
    if(state->evaluate(*action, true) > best_value)   best_action = *action;
  }

  return best_action;
}