#include <iostream>
#include <limits>
#include <queue>

#include "include/utils/state_repr.hpp"
#include "include/utils/unmove/left_from_left.hpp"
#include "include/utils/unmove/prev_states.hpp"
#include "include/utils/unmove/undistribute.hpp"
#include "include/utils/unmove/left_from_right.hpp"
#include "include/utils/unmove/right_from_left.hpp"
#include "include/utils/unmove/right_from_right.hpp"

using namespace std;

int main(){
    State_str s = {'0', '0', '0', '1', '1', '\0'};

    Prev_State_str_vector ps = prev_states(s);
    for (auto & p : ps)
    {
        cout << p.data() << endl;
    }

    cout << "pll: " << pll(str_to_tuple(s)).data() << endl;
    cout << "plr: " << plr(str_to_tuple(s)).data() << endl;
    cout << "prl: " << prl(str_to_tuple(s)).data() << endl;
    cout << "prr: " << prr(str_to_tuple(s)).data() << endl;

    cout << "dist" <<endl;
    for (auto p : undistribution(str_to_tuple(s)))
    {
        cout << p.data() << endl;
    }



    return 0;
}