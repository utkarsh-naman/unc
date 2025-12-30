//
// Created by utnam on 12/27/2025.
//


#include <algorithm>

#include "serializer.hpp"
#include "engine_unc.hpp"

using State_str = array<unsigned char, 6>;
using Move_str = array<unsigned char, 3>;



UncEngine::UncEngine() : game_map(load_map("map_final"))
{

};

std::string UncEngine::play(const std::string& og_state_str) const
{
    State_str og_state;
    og_state[0] = static_cast<unsigned char>(og_state_str[0]);
    og_state[1] = static_cast<unsigned char>(og_state_str[1]);
    og_state[2] = static_cast<unsigned char>(og_state_str[2]);
    og_state[3] = static_cast<unsigned char>(og_state_str[3]);
    og_state[4] = static_cast<unsigned char>(og_state_str[4]);
    og_state[5] = '\0';
    State_str state = sort_state(og_state);
    string move;
    const auto& move_options = game_map.at(state).next_states;

    if (move_options.empty()){ return move;} //case 1: terminal state

    bool is_all_ninf = all_of(
        move_options.begin(),
        move_options.end(),
        [&](const State_str& child)
        {
            return game_map.at(child).score == NegInfinity;
        }
    );

    // case2: bot can definitely be defeated my an omniscient player.
    // If player is not omniscient we take the option that takes longest time to be defeated so the opponent might play a bad move
    if (is_all_ninf)
    {
        auto it = max_element(
            move_options.begin(),
            move_options.end(),
            [&] (const State_str& a, const State_str& b)
            {
                return game_map.at(a).losedepth < game_map.at(b).losedepth;
            }
        );

        return move_played(og_state, *it);

    }

    // case 3: when we know that we can't be defeated even by omniscient opponent
    auto it = max_element(
        move_options.begin(),
        move_options.end(),
        [&] (const State_str& a, const State_str& b)
        {
            return game_map.at(a).score < game_map.at(b).score;
        }
    );

    return move_played(og_state, *it);

};

State_str UncEngine::sort_state(const State_str& state)
{
    State_str t{};
    t[0] = '0'+ min(static_cast<short>(static_cast<short>(state[0])-48), static_cast<short>(static_cast<short>(state[1])-48));
    t[1] = '0'+ max(static_cast<short>(static_cast<short>(state[0])-48), static_cast<short>(static_cast<short>(state[1])-48));
    t[2] = '0'+ min(static_cast<short>(static_cast<short>(state[2])-48), static_cast<short>(static_cast<short>(state[3])-48));
    t[3] = '0'+ max(static_cast<short>(static_cast<short>(state[2])-48), static_cast<short>(static_cast<short>(state[3])-48));;
    t[4] = '0'+ static_cast<short>(static_cast<short>(state[4])-48);
    t[5] = '\0';
    return t;
}

string UncEngine::move_played(const State_str& og_state_i, State_str state_f)
{
    Move_str move{};
    std::string move_str;
    move[2] = '\0';
    const int rl_i = (static_cast<int>(og_state_i[0])-48);
    const int rr_i = (static_cast<int>(og_state_i[1])-48);
    const int ul_i = (static_cast<int>(og_state_i[2])-48);
    const int ur_i = (static_cast<int>(og_state_i[3])-48);
    const int attacker_i = (static_cast<int>(og_state_i[4])-48);

    const int rl_f = (static_cast<int>(state_f[0])-48);
    const int rr_f = (static_cast<int>(state_f[1])-48);
    const int ul_f = (static_cast<int>(state_f[2])-48);
    const int ur_f = (static_cast<int>(state_f[3])-48);

    if (attacker_i == 0) // attacker was r
    {
        if (ul_f == min(ul_i, ur_i)) // r distributed
        {
            // r swaps
            // move[0] = 's';
            // move[1] = '0'+ rl_f;
            move_str = 's'+ static_cast<char>(rl_f);
            return move_str;
        }




        if (ul_f == (ul_i+rl_i)%5 && ur_f == ur_i) // r: l->l
        {
            // move[0] = 'l';
            // move[1] = 'l';
            move_str = "ll";
            return move_str;
        }
        if (ul_f == (ul_i+rl_i)%5 && ur_f != ur_i) // r: l->l
        {
            // move[0] = 'l';
            // move[1] = 'r';
            move_str = "lr";
            return move_str;
        }




        if (ul_f == (ul_i+rr_i)%5 && ur_f == ur_i) // r: r->l
        {
            // move[0] = 'r';
            // move[1] = 'l';
            move_str = "rl";
            return move_str;
        }
        if (ul_f == (ul_i+rr_i)%5 && ur_f != ur_i) // r: r->l
        {
            // move[0] = 'r';
            // move[1] = 'r';
            move_str = "rr";
            return move_str;
        }




        if (ur_f == (ur_i+rl_i)%5 && ul_f == ul_i) // r: l->r
        {
            // move[0] = 'l';
            // move[1] = 'r';
            move_str = "lr";
            return move_str;
        }
        if (ur_f == (ur_i+rl_i)%5 && ul_f != ul_i) // r: l->r
        {
            // move[0] = 'l';
            // move[1] = 'l';
            move_str = "ll";
            return move_str;
        }




        if (ur_f == (ur_i+rr_i)%5 && ul_f == ul_i) // r: r->r
        {
            // move[0] = 'r';
            // move[1] = 'r';
            move_str = "rr";
            return move_str;
        }
        if (ur_f == (ur_i+rr_i)%5 && ul_f != ul_i) // r: r->r
        {
            // move[0] = 'r';
            // move[1] = 'l';
            move_str = "rl";
            return move_str;
        }
    }


    if (rl_f == min(rl_i, rr_i)) // u distributes
    {
        // move[0] = 's';
        // move[1] = '0'+ ul_f;
        move_str = 's'+static_cast<char>(ul_f);
        return move_str;
    }

    if (rl_f == (rl_i+ul_i)%5 && rr_f == rr_i) // u: l->l
    {
        // move[0] = 'l';
        // move[1] = 'l';
        move_str = "ll";
        return move_str;
    }
    if (rl_f == (rl_i+ul_i)%5 && rr_f != rr_i) // u: l->l
    {
        // move[0] = 'l';
        // move[1] = 'r';
        move_str = "lr";
        return move_str;
    }

    if (rl_f == (rl_i+ur_i)%5 && rr_f == rr_i) // u: r->l
    {
        // move[0] = 'r';
        // move[1] = 'l';
        move_str = "rl";
        return move_str;
    }
    if (rl_f == (rl_i+ur_i)%5 && rr_f != rr_i) // u: r->l
    {
        // move[0] = 'r';
        // move[1] = 'r';
        move_str = "rr";
        return move_str;
    }

    if (rr_f == (rr_i+ul_i)%5 && rl_f == rl_i) // u: l->r
    {
        // move[0] = 'l';
        // move[1] = 'r';
        move_str = "lr";
        return move_str;
    }
    if (rr_f == (rr_i+ul_i)%5 && rl_f != rl_i) // u: l->r
    {
        // move[0] = 'l';
        // move[1] = 'l';
        move_str = "ll";
        return move_str;
    }

    if (rr_f == max((rr_i+ur_i)%5, rl_i) && rl_f == rl_i)
    {
        // move[0] = 'r';
        // move[1] = 'r';
        move_str = "rr";
        return move_str;
    }
    // u: r->l
    // move[0] = 'r';
    // move[1] = 'l';
    move_str = "rl";
    return move_str;
}



