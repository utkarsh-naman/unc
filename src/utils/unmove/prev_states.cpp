//
// Created by utnam on 12/23/2025.
//

#include <algorithm>

#include "../../../include/utils/unmove/left_from_left.hpp"
#include "../../../include/utils/unmove/left_from_right.hpp"
#include "../../../include/utils/unmove/right_from_left.hpp"
#include "../../../include/utils/unmove/right_from_right.hpp"
#include "../../../include/utils/unmove/undistribute.hpp"

Prev_State_str_vector prev_states(const State_str& state_str)
{
    State_tuple state = str_to_tuple(state_str);
    Next_State_str_vector prev_states_str_vector;
    State_str temp = pll(state);
    auto it = find(prev_states_str_vector.begin(), prev_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == prev_states_str_vector.end()) prev_states_str_vector.push_back(pll(state));
    temp = plr(state);
    it = find(prev_states_str_vector.begin(), prev_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == prev_states_str_vector.end()) prev_states_str_vector.push_back(plr(state));
    temp = prl(state);
    it = find(prev_states_str_vector.begin(), prev_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == prev_states_str_vector.end()) prev_states_str_vector.push_back(prl(state));
    temp = prr(state);
    it = find(prev_states_str_vector.begin(), prev_states_str_vector.end(), temp);
    if (temp[0] != '\0' && it == prev_states_str_vector.end()) prev_states_str_vector.push_back(prr(state));

    Next_State_str_vector udp_list = undistribution(state);
    for (auto udps: udp_list )
    {
        prev_states_str_vector.push_back(udps);
    }

    Prev_State_str_vector impossible_states;
    State_str s1 = {'0', '0', '0', '0', '0', '\0'};
    State_str s2 = {'0', '0', '0', '0', '0', '\0'};
    State_str s3 = {'3', '4', '4', '4', '0', '\0'};
    State_str s4 = {'4', '4', '3', '4', '1', '\0'};
    State_str s5 = {'4', '4', '4', '4', '0', '\0'};
    State_str s6 = {'4', '4', '4', '4', '1', '\0'};

    impossible_states.push_back(s1); impossible_states.push_back(s2); impossible_states.push_back(s3); impossible_states.push_back(s4); impossible_states.push_back(s5); impossible_states.push_back(s6);

    for (auto is: impossible_states)
    {
        prev_states_str_vector.erase(
        remove(prev_states_str_vector.begin(), prev_states_str_vector.end(), is),
        prev_states_str_vector.end()
        );
    }

    return prev_states_str_vector;
}