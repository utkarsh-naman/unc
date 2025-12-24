//
// Created by utnam on 12/23/2025.
//

#include "../include/map.hpp"

#include <algorithm>
#include <iostream>

#include "../include/utils/moves/next_state.hpp"

#include <map>
#include <queue>
#include <variant>

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
        cout << "\n";
    }
}



Map bfs_create(State_str start)
{
    Map map_0;
    vector<State_str> visited;
    visited.push_back(start);
    queue<State_str> to_visit_queue;
    to_visit_queue.push(start);

    while(!to_visit_queue.empty())
    {
        State_str state_node = to_visit_queue.front();
        to_visit_queue.pop();
        Next_State_str_vector next_state_str_vector = next_states(state_node);
        State_Properties state_props; state_props.next_states = next_state_str_vector;

        map_0[state_node] = state_props;

        for (State_str child: next_state_str_vector)
        {
            auto it = find(visited.begin(), visited.end(), child);
            if (it == visited.end()) // not in visited
            {
                visited.push_back(child);
                to_visit_queue.push(child);
            }
        }
    }
    return map_0;
}


Map init_map()
{
    State_str state = {'1', '1', '1', '1', '0', '\0'};
    return bfs_create(state);
}

