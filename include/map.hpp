//
// Created by utnam on 12/23/2025.
//

#ifndef CS_CPP_MAP_HPP
#define CS_CPP_MAP_HPP

#include <map>

#include "utils/state_repr.hpp"
#include "utils/moves/next_state.hpp"

struct State_Properties
{
    float score = 0.0f;
    vector<State_str> next_states;
};

using Map = map<State_str, State_Properties>;
Map init_map();
void print_map(const Map& map_0);
#endif //CS_CPP_MAP_HPP