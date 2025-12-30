//
// Created by utnam on 12/30/2025.
//

#include <emscripten/bind.h>
#include "engine_unc.hpp"

using namespace emscripten;

// This block registers your C++ class so JavaScript can use it.
EMSCRIPTEN_BINDINGS(my_game_module) {

    // We expose the class 'UncEngine' as 'UncEngine' in JS
    class_<UncEngine>("UncEngine")

        // Expose the constructor
        .constructor<>()

        // Expose the 'play' function
        // Embind automatically handles the conversion between
        // JS Strings <-> C++ std::string
        .function("play", &UncEngine::play);
}