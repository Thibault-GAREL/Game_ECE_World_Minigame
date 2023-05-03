cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET Code/main.c Code/Game.c Code/Game.h Code/Utils/allegroutils.c Code/Utils/allegroutils.h Code/Utils/Magical.c Code/Utils/Magical.h Code/Utils/UI.c Code/Utils/UI.h Code/Utils/Vector.h Code/Utils/Vector.c Code/Games/Exemple/GameExemple.c Code/Games/Exemple/GameExemple.h Code/Games/PecheAuCanards/PAC.c Code/Games/PecheAuCanards/PAC.h Code/Games/Snake/Snake.c Code/Games/Snake/Snake.h Code/Games/Traverse_de_la_riviere/Traverse_code.c Code/Games/Traverse_de_la_riviere/Traverse_code.h Code/Games/DarkPiano/DarkPiano.c Code/Games/DarkPiano/DarkPiano.h Code/Games/TestMap/Map.c Code/Games/TestMap/Map.h Code/Menu/Menu.c Code/Menu/Menu.h Code/Games/TirAuBallon/GameExemple.c Code/Games/TirAuBallon/GameExemple.h)
target_link_libraries(PROJET -lmingw32 -lallegro-5.0.10-monolith-md-debug)