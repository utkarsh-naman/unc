//
// Created by utnam on 12/26/2025.
//
#include <iostream>
#include "../../include/map-.hpp"
#include "../../include/utils/p_serializer.hpp"

int main()
{
    PMap map_p_0 = init_p_map();
    save_p_map(map_p_0, "../../bin/output/map/unvalued/map_p_0");
    return 0;
}