//
// Created by utnam on 12/23/2025.
//

#include "../../../include/utils/moves/next_state.hpp"
#include "../../../include/utils/moves/left_to_left.hpp"
#include "../../../include/utils/moves/left_to_right.hpp"
#include "../../../include/utils/moves/right_to_left.hpp"
#include "../../../include/utils/moves/right_to_right.hpp"
#include "../../../include/utils/moves/distribute.hpp"
#include "../../../include/utils/state_repr.hpp"

Next_State_str_vector next_states(const State_tuple& state)
{
    Next_State_str_vector next_states_str_vector;
    State_str temp = ll(state);
    if (temp[0] != '\0') next_states_str_vector.push_back(ll(state));
    temp = lr(state);
    if (temp[0] != '\0') next_states_str_vector.push_back(lr(state));
    temp = rl(state);
    if (temp[0] != '\0') next_states_str_vector.push_back(rl(state));
    temp = rr(state);
    if (temp[0] != '\0') next_states_str_vector.push_back(rr(state));
    Next_State_str_vector dns = distribute(state);
    for (auto dn : dns)
    {
        next_states_str_vector.push_back(dn);
    }
    return next_states_str_vector;
}