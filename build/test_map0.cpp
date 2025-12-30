//
// Created by utnam on 12/26/2025.
//

#include <iostream>
#include "../include/map.hpp"
#include "../include/utils/serializer.hpp"
using namespace std;

void print_state(const State_str& s)
{
    cout << "[ ";
    cout << s.data() << " ";
    cout << "]:\n";
}



void print_map(const Map& map_0)
{
    for (const auto& [state, props] : map_0)
    {
        print_state(state);
        cout << "\t-> score: " << props.score << "\n";

        cout << "\tnext states:\n";
        for (const State_str& next : props.next_states)
        {
            cout << "\t";
            print_state(next);
            cout << "\n";
        }
        cout << "\t-> contribution: " << props.contribution << "\n";
        cout << "\t-> windepth: " << props.windepth << "\n";
        cout << "\t-> losedepth: " << props.losedepth << "\n";
        cout << "\n";
    }
}




int main()
{
    Map map_0 = load_map("../bin/output/map/valued/map_final");
    print_map(map_0);
    return 0;
}
