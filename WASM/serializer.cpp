//
// Created by utnam on 12/23/2025.
//

#include "serializer.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Helper to write a single State_str (array of 6 bytes)


// Helper to read a single State_str
State_str read_state(ifstream& in) {
    State_str state;
    in.read(reinterpret_cast<char*>(state.data()), state.size());
    return state;
}

Map load_map(const string& filename) {
    Map map_0;
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Error opening file for reading: " << filename << endl;
        return map_0;
    }

    // 1. Read total number of entries
    size_t map_size = 0;
    in.read(reinterpret_cast<char*>(&map_size), sizeof(map_size));

    for (size_t i = 0; i < map_size; ++i) {
        // 2. Read the Key
        State_str key = read_state(in);

        State_Properties props;

        // 3. Read the Score
        in.read(reinterpret_cast<char*>(&props.score), sizeof(props.score));

        // 4. Read the size of next_states vector
        size_t vec_size = 0;
        in.read(reinterpret_cast<char*>(&vec_size), sizeof(vec_size));

        // 5. Read the next states
        props.next_states.resize(vec_size);
        for (size_t j = 0; j < vec_size; ++j) {
            props.next_states[j] = read_state(in);
        }

        // 6. Read the contribution
        in.read(reinterpret_cast<char*>(&props.contribution), sizeof(props.contribution));

        // 7. Read the windepth
        in.read(reinterpret_cast<char*>(&props.windepth), sizeof(props.windepth));

        // 8. Read the losedepth
        in.read(reinterpret_cast<char*>(&props.losedepth), sizeof(props.losedepth));


        // Insert into map
        map_0[key] = props;
    }

    in.close();
    cout << "UncEngine loaded successfully." << endl;
    return map_0;
}