//
// Created by utnam on 12/29/2025.
//

#ifndef CS_CPP_ENGINE_UNC_HPP
#define CS_CPP_ENGINE_UNC_HPP

#include <iostream>
#include "map.hpp"

using State_str = array<unsigned char, 6>;
using Move_str = array<unsigned char, 3>;


class UncEngine
{
public:
    UncEngine();

    [[nodiscard]] std::string play(const std::string& og_state) const;

private:
    const Map game_map;

    static State_str sort_state(const State_str& state);

    static std::string move_played(const State_str& state_i, State_str state_f);
};
#endif //CS_CPP_ENGINE_UNC_HPP