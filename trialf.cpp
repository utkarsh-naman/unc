#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "include/map.hpp"
#include "include/utils/serializer.hpp"
#include "include/utils/state_repr.hpp"
#include "include/utils/unmove/prev_states.hpp"
using namespace std;


void printparent(Prev_State_str_vector parent)
{
    for (auto a : parent)
    {
        cout << "\t" << a.data() << endl;
    }

}
int main()
{
    // Map map_0 = init_map();
    // save_map(map_0, "map_0");
    // cout << map_0.size() << endl;
    // print_map(map_0);

    Map map_0 = load_map("map_0");
    // print_map(map_0);
    // cout << map_0.size() << endl;
    int count = 0;
    for (const auto&[key, val_obj] : map_0)
    {
        //previous move from map
        Next_State_str_vector parentfmap;
        for (const auto&[key2, val_obj2] : map_0)
        {
            Next_State_str_vector nskey = val_obj2.next_states;
            auto it = find(nskey.begin(), nskey.end(), key);
            if (it != nskey.end()) parentfmap.push_back(key2);
        }

        //parents from parent_function
        Prev_State_str_vector parentffunction = prev_states(key);


        // now compare these two vectors
        sort(parentfmap.begin(), parentfmap.end());
        sort(parentffunction.begin(), parentffunction.end());

        bool are_current_parent_solution_for_current_key_same = (parentfmap == parentffunction);


        if (are_current_parent_solution_for_current_key_same == false)
        {
            count++;
            cout << "wrong solution for key: " << key.data() << endl;
            cout << "parent from map: " << endl;
            printparent(parentfmap);
            cout <<"parent from func: " << endl;
            printparent(parentffunction);
        }

    }
    cout << count << endl;
    return 0;
}