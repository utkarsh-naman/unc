//
// Created by utnam on 12/23/2025.
//

#include "../../include/utils/serializer.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Helper to write a single State_str (array of 6 bytes)
void write_state(ofstream& out, const State_str& state) {
    out.write(reinterpret_cast<const char*>(state.data()), state.size());
}

// Helper to read a single State_str
State_str read_state(ifstream& in) {
    State_str state;
    in.read(reinterpret_cast<char*>(state.data()), state.size());
    return state;
}

void save_map(const Map& map_0, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    // 1. Write total number of entries in the map
    size_t map_size = map_0.size();
    out.write(reinterpret_cast<const char*>(&map_size), sizeof(map_size));

    for (const auto& [key, props] : map_0) {
        // 2. Write the Key (State_str)
        write_state(out, key);

        // 3. Write the Score (int)
        out.write(reinterpret_cast<const char*>(&props.score), sizeof(props.score));

        // 4. Write the size of the next_states vector
        size_t vec_size = props.next_states.size();
        out.write(reinterpret_cast<const char*>(&vec_size), sizeof(vec_size));

        // 5. Write the actual next states
        for (const auto& next_s : props.next_states) {
            write_state(out, next_s);
        }

        // 6. Write the contribution
        out.write(reinterpret_cast<const char*>(&props.contribution), sizeof(props.contribution));

        // 7. Write the windepth
        out.write(reinterpret_cast<const char*>(&props.windepth), sizeof(props.windepth));

        // 8. Write the losedepth
        out.write(reinterpret_cast<const char*>(&props.losedepth), sizeof(props.losedepth));

    }
    out.close();
    cout << "Map saved successfully to " << filename << endl;
}

Map load_map(const string& filename) {
    Map map_0;
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Error opening file for reading: " << filename << endl;
        return map_0;
    }

    // 1. Read total number of entries
    uint64_t map_size = 0;
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
    cout << "Map loaded successfully from " << filename << endl;
    return map_0;
}