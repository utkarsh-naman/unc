//
// Created by utnam on 12/23/2025.
//

#ifndef CS_CPP_SERIALIZER_HPP
#define CS_CPP_SERIALIZER_HPP

#include "map.hpp"
#include <string>

// Saves the map to a binary file
void save_map(const Map& map_0, const std::string& filename);

// Loads the map from a binary file
Map load_map(const std::string& filename);
#endif //CS_CPP_SERIALIZER_HPP