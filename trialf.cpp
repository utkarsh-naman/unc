#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "include/utils/moves/left_to_left.hpp"
#include "include/utils/moves/left_to_right.hpp"
#include "include/utils/moves/right_to_left.hpp"
#include "include/utils/moves/right_to_right.hpp"
#include "include/utils/moves/distribute.hpp"
#include "include/utils/moves/next_state.hpp"
#include "include/utils/state_repr.hpp"
int main()
{
    State_tuple s1;
    get<0>(get<0>(s1)) = 0;
    get<1>(get<0>(s1)) = 1;
    get<0>(get<1>(s1)) = 0;
    get<1>(get<1>(s1)) = 4;
    get<2>(s1) = 0;

    Next_State_str_vector next_state = next_states(s1);

    for (auto & i : next_state)
    {
        cout << i.data() << '\n';
    }

    //Player 2 attacks
    get<2>(s1) = 1;
    Next_State_str_vector next_state2 = next_states(s1);

    for (auto & i : next_state2)
    {
        cout << i.data() << '\n';
    }

    // State_str s1 = {0};
    // cout << s1.data() << endl;
    return 0;
}