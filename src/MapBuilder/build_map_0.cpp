//
// Created by utnam on 12/26/2025.
//

#include "../../include/map.hpp"
#include "../../include/utils/serializer.hpp"

int main()
{
    Map map_0 = init_map();
    save_map(map_0, "../bin/output/map/unvalued/map_0");
    return 0;
}