<img width="100%"  alt="hand-image" src="https://github.com/user-attachments/assets/fda7294f-c7c0-4c3d-b7cf-8e1a41740c62"/>

>This repo is for the knowledge transfer of the solution to the hand-game 'chopsticks' to the public.</br>

# Test the bot <a href="">Link will be added soon</a>


# About the game
The game of Chopsticks is a two-player strategic hand game often introduced as a simple pastime.  
The game commences with each player having one finger on each hand. Players take turns tapping an opponent’s hand,
with the finger count of the tapped hand increasing by the count of the attacking hand, and the result is
taken modulo 5.

In addition to attacking, players can also redistribute their total finger count between their own two hands.  
There is also a “suicide” rule, which allows a player to perform a redistribution that intentionally results in one of their own hands having a count of zero.

# Approach
Unlike other two player games in which players take turn like chess or tic tac toe which have game tree where you can either win, lose or tie thus have an end, chopsticks is a game that follows a graph where you can either win, lose or play infinitely, therefore it cannot be solved by MiniMax which follows a top-bottom approach.

To solve this, I created a similar approach similar to MiniMax which I will call MaxiMax, where each player wants to have their score as maximum. (**Note**: I could have used Minimax but to make the bot engine able to play using a single function, I chose this method.)

I used bottom-top approach, starting from the winning states, i set their score to be infinity (if the bot wins by tapping on the opponent) & -infinity (if the opponent commits suicide), then set the score of for all the parent nodes of these infinity score nodes as -infinity so that bot won't play that move while playing as opponent. Then for each of these parent if all their children nodes have -infinity scores then set their scores as infinity and continue.
Do the same for the nodes where the opponent wins.

# Build Instructions
```cmd
cd src/MapBuilder
clang++ -std=c++17 (Get-Content build_map_0.txt) -o map0builder.exe
./map0builder
```

``` cmd
cd src/MapBuilder
clang++ -std=c++17 (Get-Content build_map_p_0.txt) -o map_p0builder.exe
./map0builder
```

```cmd
cd src/MapBuilder
clang++ -std=c++17 (Get-Content set_suicide.txt) -o suicide_setter.exe
./suicide_setter
```

```cmd
cd src/MapValueSetter
clang++ -std=c++17 (Get-Content terminal_depth_setter.txt) -o depthsetter.exe
./depthsetter
```

```cmd
cd src/MapValueSetter
clang++ -std=c++17 (Get-Content set_score.txt) -o scoresetter.exe
./scoresetter
```

```cmd
cd WASM
emcc engine_unc.cpp serializer.cpp bindings.cpp -o chopsticks_bot.js -std=c++17 -lembind --preload-file map_final -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -s MODULARIZE=1 -s EXPORT_NAME="createChopsticksModule" -O3
```

## To run
```cmd
cd WASM
emrun index.html
```

# 
<img width="100%"  alt="creation-of-unc-image" src="https://github.com/user-attachments/assets/2489f04b-6ef7-4194-bc13-f8bd87aab5d3"/>

>To be honest, this repo serves as gift of gratitude to the person who used to be one of my dearest and closest friends, who taught me the hand-game 'chopsticks' and to the future generations<!-- I wish I could have with her-->. She used to deafeat me every single time. So, I solved it. Realizing the fact that we would be busy with our lives, I made this so she would be able to play with this bot only to lose or play infinitely but never win.</br>
>ദ്ദി(  - ᴗ •́  )</br>

