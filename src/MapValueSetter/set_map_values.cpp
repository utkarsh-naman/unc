//
// Created by utnam on 12/25/2025.
//

#include "../../include/gamebot/set_map_values.hpp"

#include <algorithm>

#include "../../include/map.hpp"
#include "../../include/utils/serializer.hpp"
#include "../../include/map-.hpp"
#include "../../include/rules.hpp"
#include "../../include/utils/p_serializer.hpp"
#include "../../include/utils/state_repr.hpp"


void u_wins();
void r_loses();

vector<State_str> u_wins_vec(const Map& map_0)
{
    vector<State_str> u_wins_vector;
    for (auto [key, value] : map_0)
    {
        if (get<1>(get<0>(str_to_tuple(key))) == 0) u_wins_vector.push_back(key);
    }

    return u_wins_vector;
}


vector<State_str> r_wins_vec(const Map& map_0)
{
    vector<State_str> r_wins_vector;
    for (auto [key, value] : map_0)
    {
        if (get<1>(get<1>(str_to_tuple(key))) == 0) r_wins_vector.push_back(key);
    }

    return r_wins_vector;
}

Map map_f = load_map("../../bin/output/map/unvalued/map_0");
PMap map_p_f = load_p_map("map_parent_0");
vector<State_str> u_wins_vector  = u_wins_vec(map_f);
vector<State_str> r_lose_vector;
vector<State_str> worked_history;

void u_wins()
{
    if (u_wins_vector.empty()) return;
    r_lose_vector.clear(); //empty the r_lose_vector to make it contain r_lose state of single level.
    for (State_str uw_key: u_wins_vector)
    {
        // cases where u defeats r : next chance is of r, i.e. 0
        if (uw_key[4] == '0')
        {
            map_f[uw_key].score = Infinity;
            for (State_str parent_uw_key: map_p_f[uw_key].previous_states)
            {
                // parent not in worked history
                auto it = find(worked_history.begin(), worked_history.end(), parent_uw_key);
                if (it == worked_history.end())
                {
                    map_f[parent_uw_key].score = NegInfinity;
                    r_lose_vector.push_back(parent_uw_key);
                    worked_history.push_back(uw_key);
                }
            }
        }

        // cases where r loses due to suicide: : next chance is of r, i.e. 0
        else
        {
            map_f[uw_key].score = NegInfinity;
            r_lose_vector.push_back(uw_key);
        }




    }
    r_loses();
    return;
}

void r_loses()
{
    if (r_lose_vector.empty()) return;
    u_wins_vector.clear();

    for (State_str rl_key: r_lose_vector)
    {
        for (State_str parent_rl_key: map_p_f[rl_key].previous_states)
        {
            auto it = find(worked_history.begin(), worked_history.end(), parent_rl_key);
            if (it == worked_history.end())
            {
                vector<State_str> children = map_f[parent_rl_key].next_states;
                bool isall_ninf = all_of(
                    children.begin(), children.end(),
                    [](const State_str& x) {
                        return map_f[x].score == NegInfinity;
                    }
                );
                if (isall_ninf) u_wins_vector.push_back(parent_rl_key);
            }
        }
    }

    u_wins();
    return;
}


void set_map()
{
    u_wins();
    save_map(map_f, "map_f_set");
}