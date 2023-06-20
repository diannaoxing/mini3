#include <cstdlib>
#include "../state/state.hpp"
#include "./submission.hpp"

#define INT_MAX  2147483647
#define INT_MIN -2147483648

int best_A, best_B;

/**
 * @brief get the best action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */


Move Submission::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  // todo: use alphbeta_search to determine which action to choose
  Move best_action;
  int tmp_value, best_value = INT_MIN;
  for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
    tmp_value = AB_search(state->next_state(*action), depth, INT_MIN, INT_MAX, false);
    if(tmp_value > best_value){
        best_action = *action;
        best_value = tmp_value;
    }
  }
  return best_action;
}

int AB_search(State* state, int depth, int A, int B, bool maximizingPlayer){
    
    int value;
    State* tmp;
    if(depth == 0)   return state->evaluate2(maximizingPlayer);
    
    if(maximizingPlayer){
        value = INT_MIN;
        state->get_legal_actions();
        for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
            tmp = state->next_state(*action);
            value = max(value, AB_search(tmp, depth - 1, A, B, false));
            A = max(A, value);
            if(A >= B)  break;
        }
    return value;
    }
    else{ // minizing player
        value = INT_MAX;
        state->get_legal_actions();
        for(auto action = state->legal_actions.begin(); action != state->legal_actions.end(); action++){
            tmp = state->next_state(*action);
            value = min(value, AB_search(tmp, depth - 1, A, B, true));
            B = min(B, value);
            if(B <= A)  break;
        }
    return value;
    }
}