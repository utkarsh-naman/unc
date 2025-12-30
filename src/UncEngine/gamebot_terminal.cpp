//
// Created by utnam on 12/29/2025.
//


#include "engine_unc.hpp"

int main()
{
    UncEngine engine = UncEngine();
    State_str g_state = {'3', '2', '3', '1', '0', '\0'};
    cout << "GAME START" << endl;
    cout << "STATE:\t" << g_state[0] << " " << g_state[1] << " " << g_state[2] << " " << g_state[3] << " " << endl;
    cout << "Turn:\t" << ((g_state[4] == '1')? "Bot\'s": "Yours") << endl;
    Move_str bot_move = engine.play(g_state);
    cout << "Bot's move:\t" << bot_move.data() << endl;
}