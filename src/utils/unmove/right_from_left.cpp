//
// Created by utnam on 12/24/2025.
//

#include "../../../include/rules.hpp"
#include "../../../include/utils/mod.hpp"
#include "../../../include/utils/unmove/right_from_left.hpp"
#include "../../../include/utils/unmove/arrange_attacker_victim.hpp"

State_str prl(const State_tuple& state)
{
    State_str rl_prev_state_str = {0};
    Player attacker;
    Player victim;
    auto a_index = static_cast<short>(get<2>(state)^1);

    if (a_index == 0)
    {
        attacker = get<0>(state);
        victim = get<1>(state);
    }
    else
    {
        attacker = get<1>(state);
        victim = get<0>(state);
    }


    // if the victim of previous state is 0 then it can't reach current state
    if (get<1>(victim) - get<0>(attacker) == 0) return rl_prev_state_str;
    // if previous attacking hand is 0 then how could he hit
    if (get<0>(attacker) == 0) return rl_prev_state_str;
    get<1>(victim) = mod( static_cast<short>(get<1>(victim) - get<0>(attacker)), MAX_FINGER);

    const short temp_0 = min(get<0>(victim), get<1>(victim));
    const short temp_1 = max(get<0>(victim), get<1>(victim));
    get<0>(victim) = temp_0;
    get<1>(victim) = temp_1;
    return arrange_state_un(state, victim);
}