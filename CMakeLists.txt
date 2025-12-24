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
        src/map.cpp
        include/map.hpp
        src/utils/unmove/prev_states.cpp
        include/utils/unmove/prev_states.hpp
        src/utils/unmove/left_from_left.cpp
        include/utils/unmove/left_from_left.hpp
        src/utils/serializer.cpp
        include/utils/serializer.hpp
        src/utils/mod.cpp
        include/utils/mod.hpp
        src/utils/unmove/left_from_right.cpp
        include/utils/unmove/left_from_right.hpp
        src/utils/unmove/right_from_left.cpp
        include/utils/unmove/right_from_left.hpp
        src/utils/unmove/right_from_right.cpp
        include/utils/unmove/right_from_right.hpp
        src/utils/unmove/undistribute.cpp
        include/utils/unmove/undistribute.hpp
        src/utils/unmove/arrange_for_undistribution.cpp
        include/utils/unmove/arrange_for_undistribution.hpp
        concepts.cpp
)
