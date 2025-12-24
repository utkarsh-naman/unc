//
// Created by utnam on 12/24/2025.
//

#include "../../../include/utils/unmove/undistribute.hpp"
#include "../../../include/utils/unmove/arrange_for_undistribution.hpp"
#include <algorithm>
#include "../../../include/rules.hpp"
#include "../../../include/utils/mod.hpp"


static vector<Player> undistribution_pairs(Player fingers)
{
    vector<tuple<short, short>> undistribution_pairs_list;
    undistribution_pairs_list.push_back(fingers);
    //some code here
    auto sum = static_cast<short>(get<0>(fingers)+get<1>(fingers));
    for (short i = 0; i < MAX_FINGER; i++)
    {
        for (short j = i; j < MAX_FINGER; j++)
        {
            Player unsol_i;
            get<0>(unsol_i) = i;
            get<1>(unsol_i) = j;
            auto it = find(undistribution_pairs_list.begin(), undistribution_pairs_list.end(), unsol_i);
            if ( ((i+j) == sum || (mod(static_cast<short>(i+j), MAX_FINGER) == sum)) && (it == undistribution_pairs_list.end())) undistribution_pairs_list.push_back(unsol_i);
        }
    }

    return undistribution_pairs_list;
}



Prev_State_str_vector undistribution(const State_tuple& state)
{
    Prev_State_str_vector undistribution_list;


    Player attacker; // who will distribute
    Player victim;
    auto attacker_index = static_cast<short>(get<2>(state)^1);

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

    // if previous victim has 00 then why will previous attacker distribute? So no undistribution for current state
    if (get<1>(victim) == 0) return undistribution_list;

    vector<Player> udp = undistribution_pairs(attacker);
    if (udp.size() == 1) return undistribution_list;
    for (short i = 1; i < udp.size(); i++)
    {
        Player n_attacker = udp[i];
        undistribution_list.push_back(arrange_undist(state, n_attacker));
    }

    return undistribution_list;
}