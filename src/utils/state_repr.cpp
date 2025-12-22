//
// Created by utnam on 12/20/2025.
//

#include "../../include/utils/state_repr.hpp"
#include <algorithm>
using namespace std;

State_tuple str_to_tuple(const State_str& state)
{
    State_tuple t;
    get<0>(get<0>(t)) = static_cast<short>(static_cast<short>(state[0])-48);
    get<1>(get<0>(t)) = static_cast<short>(static_cast<short>(state[1])-48);
    get<0>(get<1>(t)) = static_cast<short>(static_cast<short>(state[2])-48);
    get<1>(get<1>(t)) = static_cast<short>(static_cast<short>(state[3])-48);
    get<2>(t) = static_cast<short>(static_cast<short>(state[4])-48);
    return t;
}

State_str tuple_to_str(const State_tuple& state_tuple)
{
    State_str t = {0};
    t[0] = '0'+ get<0>(get<0>(state_tuple));
    t[1] = '0'+ get<1>(get<0>(state_tuple));
    t[2] = '0'+ get<0>(get<1>(state_tuple));
    t[3] = '0'+ get<1>(get<1>(state_tuple));
    t[4] = '0'+ get<2>(state_tuple);
    t[5] = '\0';
    return t;
}

bool state_str_empty(const State_str& state)
{
    return all_of(state.begin(), state.end(), [](unsigned char c) { return c == 0; });
}