//
// Created by utnam on 12/23/2025.
//

#ifndef CS_CPP_MAP_HPP
#define CS_CPP_MAP_HPP

#include <limits>
#include <map>
#include "state_repr.hpp"

constexpr float Infinity = numeric_limits<float>::infinity();
constexpr float NegInfinity = -numeric_limits<float>::infinity();

struct State_Properties
{
    float score = 0.0f;
    vector<State_str> next_states;
    short contribution = 1;
    float windepth = Infinity;
    float losedepth = Infinity;
};

using Map = map<State_str, State_Properties>;
#endif //CS_CPP_MAP_HPP