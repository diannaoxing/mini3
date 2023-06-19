#include <cstdlib>
#include "../state/state.hpp"
#include "./minimax.hpp"

#define MAX_DEPTH 5
#define INT_MAX  2147483647
#define INT_MIN -2147483648
/**
 * @brief get the best action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){ 
  if(!state->legal_actions.size())
    state->get_legal_actions();

  // todo: use minimax function to determine which action to choose
  Move best_action;
  int tmp_value, best_value = INT_MIN;
  for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
    tmp_value = minimax_search(state->next_state(*action), 1, false); // next state是opponent的state, 所以false
    if(tmp_value > best_value){
        best_action = *action;
        best_value = tmp_value;
    }
  }
  return best_action;
}

int minimax_search(State* state, int depth, bool maximizingPlayer){
    
    int value;
    Move doNothing = {{1,1} , {1,1}};
    if(depth == MAX_DEPTH/* || node is a terminal node*/)   return state->evaluate(doNothing, maximizingPlayer);
    
    if(maximizingPlayer){
        value = INT_MIN;
        state->get_legal_actions();
        for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
            State* tmp = state->next_state(*action);
            value = max(value, minimax_search(tmp, depth + 1, false));    
        }
      return value;
    }
    else{ // minizing player
        value = INT_MAX;
        state->get_legal_actions();
        for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
            State* tmp = state->next_state(*action);
            value = min(value, minimax_search(tmp, depth + 1, true));
        }    
      return value;
    }
}