//
// Created by utnam on 12/20/2025.
//

#ifndef CS_CPP_STATE_REPR_HPP
#define CS_CPP_STATE_REPR_HPP

#include <tuple>
#include <array>
#include <vector>
using namespace std;

using Player = tuple<short, short>;
using State_tuple = tuple<Player, Player, short>;
// using State_str = unsigned char[6];
using State_str = array<unsigned char, 6>;
using Move_str = array<unsigned char, 3>;
// using Next_State_str_vector = vector<State_str>;
// using Prev_State_str_vector = vector<State_str>;

// State_tuple str_to_tuple(const State_str& state);
// State_str tuple_to_str(const State_tuple& state_tuple);
// bool state_str_empty(const State_str& state);
#endif //CS_CPP_STATE_REPR_HPP