#include <iostream>
// #include <limits>
// #include <queue>

#include "include/utils/state_repr.hpp"
#include "include/utils/moves/next_state.hpp"
#include "include/utils/unmove/prev_states.hpp"

using namespace std;

int main(){
    State_str s2 = {'0', '1', '1', '1', '0', '\0'};
    Prev_State_str_vector ns = next_states(s2);
    for (State_str nss : ns)
    {
        cout << nss.data() << endl;
    }

    cout << endl;

    Prev_State_str_vector ps = prev_states(s2);
    for (State_str pss : ps)
    {
        cout << pss.data() << endl;
    }

    return 0;
}