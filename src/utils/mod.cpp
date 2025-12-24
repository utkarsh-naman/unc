//
// Created by utnam on 12/24/2025.
//

#include "../../include/utils/mod.hpp"

short mod(const short &a, const short &b)
{
    if ((a >= 0 && b >= 0) || (a < 0 && b < 0)) return a%b;
    else return a%b+b;
}
