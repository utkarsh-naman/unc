//
// Created by utnam on 12/23/2025.
//

#include "../../../include/utils/moves/next_state.hpp"

#include <algorithm>

#include "../../../include/utils/moves/left_to_left.hpp"
#include "../../../include/utils/moves/left_to_right.hpp"
#include "../../../include/utils/moves/right_to_left.hpp"
#include "../../../include/utils/moves/right_to_right.hpp"
#include "../../../include/utils/moves/distribute.hpp"
#include "../../../include/utils/state_repr.hpp"

Next_State_str_vector next_states(const State_str& state_str)
{
    State_tuple state = str_to_tuple(state_str);
    Next_State_str_vector next_states_str_vector;
    State_str temp = ll(state);
    auto it = find(next_states_str_vector.begin(), next_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == next_states_str_vector.end()) next_states_str_vector.push_back(ll(state));
    temp = lr(state);
    it = find(next_states_str_vector.begin(), next_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == next_states_str_vector.end()) next_states_str_vector.push_back(lr(state));
    temp = rl(state);
    it = find(next_states_str_vector.begin(), next_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == next_states_str_vector.end()) next_states_str_vector.push_back(rl(state));
    temp = rr(state);
    it = find(next_states_str_vector.begin(), next_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == next_states_str_vector.end()) next_states_str_vector.push_back(rr(state));
    Next_State_str_vector dns = distribute(state);
    for (auto dn : dns)
    {
        next_states_str_vector.push_back(dn);
    }
    return next_states_str_vector;
}