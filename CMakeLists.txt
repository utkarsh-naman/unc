cmake_minimum_required(VERSION 4.1)
project(cs_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(cs_cpp trialf.cpp
        reference.cpp
        include/rules.hpp
        src/utils/state_repr.cpp
        include/utils/state_repr.hpp
        src/mathematics/game_move.cpp
        src/utils/moves/left_to_left.cpp
        include/utils/moves/left_to_left.hpp
        src/utils/moves/arrange_attacker_victim.cpp
        include/utils/moves/arrange_attacker_victim.hpp
        src/utils/moves/left_to_right.cpp
        include/utils/moves/left_to_right.hpp
        src/utils/moves/right_to_left.cpp
        include/utils/moves/right_to_left.hpp
        src/utils/moves/right_to_right.cpp
        include/utils/moves/right_to_right.hpp
        src/utils/moves/distribute.cpp
        include/utils/moves/distribute.hpp
        src/utils/moves/arrange_for_distribution.cpp
        include/utils/moves/arrange_for_distribution.hpp
        src/utils/moves/next_state.cpp
        include/utils/moves/next_state.hpp
)
