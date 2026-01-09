//
// Created by utnam on 12/29/2025.
//


#include "engine_unc.hpp"

int main()
{
    UncEngine engine = UncEngine();
    string g_state = "02041";
    cout << "GAME START" << endl;
    cout << "STATE:\t" << g_state[0] << " " << g_state[1] << " " << g_state[2] << " " << g_state[3] << " " << endl;
    cout << "Turn:\t" << ((g_state[4] == '1')? "Bot\'s": "Yours") << endl;
    string bot_move = engine.play(g_state);
    cout << "Bot's move: " << bot_move.data() << endl;
}