//
// Created by utnam on 12/26/2025.
//

#include <iostream>
#include "set_suicides.hpp"
// #include "../../include/map.hpp"
#include "../../include/utils/serializer.hpp"
#include "../../include/utils/state_repr.hpp"

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



vector<State_str> r_suicide_vec(const Map& map_0)
{
    vector<State_str> rsv;
    for (auto [key, value] : map_0)
    {
        if (key[1] == '0' && key[4] == '1') rsv.push_back(key);
    }

    return rsv;
}


vector<State_str> u_suicide_vec(const Map& map_0)
{
    vector<State_str> usv;
    for (auto [key, value] : map_0)
    {
        if (key[3] == '0' && key[4] == '0' ) usv.push_back(key);
    }

    return usv;
}



int main()
{
    Map map_0 = load_map("../../bin/output/map/unvalued/map_0");
    vector<State_str> rsv = r_suicide_vec(map_0);
    vector<State_str> usv = u_suicide_vec(map_0);
    for (State_str rs : rsv)
    {
        map_0[rs].contribution = 0;
    }
    for (State_str us : usv)
    {
        map_0[us].contribution = 0;
    }
    save_map(map_0, "../../bin/output/map/valued/map_1");
    return 0;
}