//
// Created by utnam on 12/21/2025.
//

#include "../../../include/utils/unmove/arrange_attacker_victim.hpp"
#include "../../../include/utils/state_repr.hpp"


State_str arrange_state_un(const State_tuple& og_state, const Player& p_victim)
{

    // const Player og_victim = get<1>(og_state);
    const short og_attacker_index = get<2>(og_state)^1;
    State_tuple prev_state_tuple;
    if (og_attacker_index == 0)
    {
        const Player og_attacker = get<0>(og_state);
        get<0>(prev_state_tuple) = og_attacker;
        get<1>(prev_state_tuple) = p_victim;
        get<2>(prev_state_tuple) = static_cast<short>(og_attacker_index);
        return tuple_to_str(prev_state_tuple);
    }
    const Player og_attacker = get<1>(og_state);
    get<0>(prev_state_tuple) = p_victim;
    get<1>(prev_state_tuple) = og_attacker;
    get<2>(prev_state_tuple) = static_cast<short>(og_attacker_index);
    return tuple_to_str(prev_state_tuple);
}
