//
// Created by utnam on 12/22/2025.
//

#include "../../../include/utils/moves/distribute.hpp"

#include <algorithm>

#include "../../../include/rules.hpp"
#include "../../../include/utils/state_repr.hpp"
#include "../../../include/utils/moves/arrange_for_distribution.hpp"

static vector<Player> distribution_pairs(Player fingers)
{
    vector<tuple<short, short>> distribution_pairs_list;
    distribution_pairs_list.push_back(fingers);
    //some code here
    auto sum = static_cast<short>(get<0>(fingers)+get<1>(fingers));
    for (short i = 0; i <= sum/2; i++)
    {
        Player sol_i;
        get<0>(sol_i) = min(i, static_cast<short>((sum-i)%MAX_FINGER));
        get<1>(sol_i) = max(i, static_cast<short>((sum-i)%MAX_FINGER));
        auto it = find(distribution_pairs_list.begin(), distribution_pairs_list.end(), sol_i);
        if (it == distribution_pairs_list.end()) distribution_pairs_list.push_back(sol_i);
    }

    return distribution_pairs_list;
}


Next_State_str_vector distribute(State_tuple state)
{
    Next_State_str_vector distribution_list;
    Player attacker;
    Player victim;
    State_tuple distribution_tuple;
    short attacker_index = get<2>(state);

    if (attacker_index == 0)
    {
        attacker = get<0>(state);
        victim = get<1>(state);
    }
    else
    {
        attacker = get<1>(state);
        victim = get<0>(state);
    }

    // in distribution, attacker is the one who gets changed.
    // call _distribution_pair, do some operation and return
    vector<Player> dp = distribution_pairs(attacker);
    if (dp.size() == 1) return distribution_list;
    for (short i = 1; i < dp.size(); i++)
    {
        Player n_attacker = dp[i];
        distribution_list.push_back(arrange_dist(state, n_attacker));
    }

    return distribution_list;
}
