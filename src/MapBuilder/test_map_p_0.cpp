//
// Created by utnam on 12/26/2025.
//

#include <iostream>
using namespace std;

#include "../../include/utils/p_serializer.hpp"
#include "../../include/utils/state_repr.hpp"

void print_p_state(const State_str& s)
{
    cout << "[ ";
    cout << s.data() << " ";
    cout << "]:\n";
}



void print_p_map(const PMap& map_0)
{
    for (const auto& [state, props] : map_0)
    {
        print_p_state(state);
        // cout << "\t-> score: " << props.score << "\n";

        cout << "\tprevious states:\n";
        for (const State_str& next : props.previous_states)
        {
            cout << "\t";
            print_p_state(next);
            cout << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    PMap map_p_0 = load_p_map("../../bin/output/map/unvalued/map_p_0");
    print_p_map(map_p_0);
    return 0;
}