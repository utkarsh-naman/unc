//
// Created by utnam on 12/24/2025.
//

#include "../../../include/utils/unmove/arrange_for_undistribution.hpp"

State_str arrange_undist(const State_tuple& og_state, const Player& p_attacker)
{

    // const Player og_victim = get<1>(og_state);
    const auto og_attacker_index = static_cast<short>(get<2>(og_state)^1);
    State_tuple prev_state_tuple;
    if (og_attacker_index == 0)
    {
        const Player og_victim = get<1>(og_state);
        get<0>(prev_state_tuple) = p_attacker;
        get<1>(prev_state_tuple) = og_victim;
        get<2>(prev_state_tuple) = static_cast<short>(og_attacker_index);
        return tuple_to_str(prev_state_tuple);
    }
    const Player og_victim = get<0>(og_state);
    get<0>(prev_state_tuple) = og_victim;
    get<1>(prev_state_tuple) = p_attacker;
    get<2>(prev_state_tuple) = static_cast<short>(og_attacker_index);
    return tuple_to_str(prev_state_tuple);
}