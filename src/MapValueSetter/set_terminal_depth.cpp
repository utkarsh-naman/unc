//
// Created by utnam on 12/26/2025.
//

#include <iostream>
#include "../../include/utils/state_repr.hpp"
#include "../../include/utils/serializer.hpp"
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



int main()
{
    Map map_1 = load_map("../../bin/output/map/valued/map_1");
    for (auto [key, value] : map_1)
    {
        if (key[1] == '0') // u wins
        {
            if (key[4] == '0') map_1[key].windepth = 0.0f; // u defeats r
            else map_1[key].losedepth = 0.0f; // r commits suicide
        }

        else if (key[3] == '0') // r wins
        {
            if (key[4] == '1') map_1[key].windepth = 0.0f; // r defeats u
            else map_1[key].losedepth = 0.0f; // u commits suicide
        }
    }

    save_map(map_1, "../../bin/output/map/valued/map_1_depth");
    return 0;
}
