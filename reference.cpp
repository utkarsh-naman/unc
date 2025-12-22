#include <iostream>

#include "include/utils/state_repr.hpp"
using namespace std;

int main(){
    array<unsigned char, 6> state_str = {0};
    cout << "state_str: " << state_str.data() << endl;
    cout << "state_str size: " << state_str.size() << endl;
    cout << "state_str empty?: " << state_str.empty() << endl;
    cout << "state_str empty with \\0?: " << (state_str[0] == '\0') << endl;
    return 0;
}