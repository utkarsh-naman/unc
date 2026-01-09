inside:
project root\wasm>

run:
emcc engine_unc.cpp serializer.cpp bindings.cpp -o chopsticks_bot.js -std=c++17 -lembind --preload-file map_final -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -s MODULARIZE=1 -s EXPORT_NAME="createChopsticksModule" -O3