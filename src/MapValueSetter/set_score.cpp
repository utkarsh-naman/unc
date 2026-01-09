//
// Created by utnam on 12/26/2025.
//

#include  <iostream>
#include "../../include/utils/state_repr.hpp"
#include "../../include/utils/serializer.hpp"
#include "../../include/utils/p_serializer.hpp"
#include <algorithm>
using namespace std;

// void print_state(const State_str& s)
// {
//     cout << "[ ";
//     cout << s.data() << " ";
//     cout << "]:\n";
// }
//
//
//
// void print_map(const Map& map_0)
// {
//     for (const auto& [state, props] : map_0)
//     {
//         print_state(state);
//         cout << "\t-> score: " << props.score << "\n";
//
//         cout << "\tnext states:\n";
//         for (const State_str& next : props.next_states)
//         {
//             cout << "\t";
//             print_state(next);
//             cout << "\n";
//         }
//         cout << "\t-> contribution: " << props.contribution << "\n";
//         cout << "\t-> windepth: " << props.windepth << "\n";
//         cout << "\t-> losedepth: " << props.losedepth << "\n";
//         cout << "\n";
//     }
// }


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

Map map_f = load_map("../../bin/output/map/valued/map_1_depth");
PMap map_p_f = load_p_map("../../bin/output/map/unvalued/map_p_0");
vector<State_str> u_wins_vector  = u_wins_vec(map_f);
vector<State_str> r_lose_vector;
vector<State_str> worked_history;

void u_wins();
void r_loses();


float max_depth(const State_str& key)
{
    const auto& children_vec = map_f.at(key).next_states;
    auto it = std::max_element(
        children_vec.begin(),
        children_vec.end(),
        [&](const State_str& a, const State_str& b) {
            return map_f.at(a).losedepth < map_f.at(b).losedepth;
        }
    );

    float md = map_f.at(*it).losedepth;
    return md;
}

float min_depth(const State_str& key)
{
    const auto& children_vec = map_f.at(key).next_states;
    auto it = std::min_element(
        children_vec.begin(),
        children_vec.end(),
        [&](const State_str& a, const State_str& b) {
            return map_f.at(a).windepth < map_f.at(b).windepth;
        }
    );

    float md = map_f.at(*it).windepth;
    return md;
}


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
            const auto& children_vec = map_f.at(uw_key).next_states;
            if (!children_vec.empty())
            {
                map_f[uw_key].windepth = max_depth(uw_key);
            }

            for (State_str parent_uw_key: map_p_f[uw_key].previous_states)
            {
                // parent not in worked history
                auto it = find(worked_history.begin(), worked_history.end(), parent_uw_key);
                if (it == worked_history.end())
                {
                    map_f[parent_uw_key].score = NegInfinity;
                    if (!map_f[parent_uw_key].next_states.empty())
                    {
                        map_f[parent_uw_key].losedepth = min_depth(parent_uw_key)+1;
                    }
                    r_lose_vector.push_back(parent_uw_key);
                    worked_history.push_back(uw_key);
                }
            }
        }

        // cases where r loses due to suicide: : next chance is of u, i.e. 1
        else
        {
            map_f[uw_key].score = NegInfinity;
            if (!map_f[uw_key].next_states.empty())
            {
                map_f[uw_key].losedepth = min_depth(uw_key)+1;
            }
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



vector<State_str> r_wins_vector  = r_wins_vec(map_f);
vector<State_str> u_lose_vector;
vector<State_str> worked_history2;

void r_wins();
void u_loses();

void r_wins()
{
    if (r_wins_vector.empty()) return;
    u_lose_vector.clear(); //empty the u_lose_vector to make it contain u_lose state of single level.
    for (State_str rw_key: r_wins_vector)
    {
        // cases where r defeats u : next chance is of u, i.e. 1
        if (rw_key[4] == '1')
        {
            map_f[rw_key].score = Infinity;
            const auto& children_vec = map_f.at(rw_key).next_states;
            if (!children_vec.empty())
            {
                map_f[rw_key].windepth = max_depth(rw_key);
            }

            for (State_str parent_rw_key: map_p_f[rw_key].previous_states)
            {
                // parent not in worked history
                auto it = find(worked_history2.begin(), worked_history2.end(), parent_rw_key);
                if (it == worked_history2.end())
                {
                    map_f[parent_rw_key].score = NegInfinity;
                    if (!map_f[parent_rw_key].next_states.empty())
                    {
                        map_f[parent_rw_key].losedepth = min_depth(parent_rw_key)+1;
                    }
                    u_lose_vector.push_back(parent_rw_key);
                    worked_history2.push_back(rw_key);
                }
            }
        }

        // cases where u loses due to suicide: : next chance is of r, i.e. 0
        else
        {
            map_f[rw_key].score = NegInfinity;
            if (!map_f[rw_key].next_states.empty())
            {
                map_f[rw_key].losedepth = min_depth(rw_key)+1;
            }
            u_lose_vector.push_back(rw_key);
        }

    }
    u_loses();
    return;
}

void u_loses()
{
    if (u_lose_vector.empty()) return;
    r_wins_vector.clear();

    for (State_str ul_key: u_lose_vector)
    {
        for (State_str parent_ul_key: map_p_f[ul_key].previous_states)
        {
            auto it = find(worked_history2.begin(), worked_history2.end(), parent_ul_key);
            if (it == worked_history2.end())
            {
                vector<State_str> children = map_f[parent_ul_key].next_states;
                bool isall_ninf = all_of(
                    children.begin(), children.end(),
                    [](const State_str& x) {
                        return map_f[x].score == NegInfinity;
                    }
                );
                if (isall_ninf) r_wins_vector.push_back(parent_ul_key);
            }
        }
    }

    r_wins();
    return;
}




int main()
{
    u_wins();
    r_wins();
    save_map(map_f, "../../bin/output/map/valued/map_final");
    return 0;
}