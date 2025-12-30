//
// Created by utnam on 12/29/2025.
//

#ifndef CS_CPP_ENGINE_UNC_HPP
#define CS_CPP_ENGINE_UNC_HPP

#include <iostream>
#include "map.hpp"
using namespace std;
using State_str = array<unsigned char, 6>;
using Move_str = array<unsigned char, 3>;


class UncEngine
{
public:
    UncEngine();


    [[nodiscard]] Move_str play(const State_str& og_state) const;

private:
    const Map game_map;

    static State_str sort_state(const State_str& state);

    static Move_str move_played(const State_str& state_i, State_str state_f);

    static Move_str unsort_move(const State_str& og_state,
                                const State_str& sorted_state,
                                const Move_str& sorted_move);
};
#endif //CS_CPP_ENGINE_UNC_HPP