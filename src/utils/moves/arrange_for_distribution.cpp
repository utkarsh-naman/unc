//
// Created by utnam on 12/23/2025.
//

#include "../../../include/utils/moves/arrange_for_distribution.hpp"
#include "../../../include/utils/state_repr.hpp"
State_str arrange_dist(const State_tuple& og_state, const Player& n_attacker)
{

    // const Player og_victim = get<1>(og_state);
    const short og_attacker_index = get<2>(og_state);
    State_tuple next_state_tuple;
    if (og_attacker_index == 0)
    {
        const Player og_victim = get<1>(og_state);
        get<0>(next_state_tuple) = n_attacker;
        get<1>(next_state_tuple) = og_victim;
        get<2>(next_state_tuple) = static_cast<short>(og_attacker_index^1);
        return tuple_to_str(next_state_tuple);
    }
    const Player og_victim = get<0>(og_state);
    get<0>(next_state_tuple) = og_victim;
    get<1>(next_state_tuple) = n_attacker;
    get<2>(next_state_tuple) = static_cast<short>(og_attacker_index^1);
    return tuple_to_str(next_state_tuple);
}
