cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET Code/main.c Code/Game.c Code/Games/Exemple/GameExemple.c Code/Utils/allegroutils.c)
target_link_libraries(PROJET -lmingw32 -lallegro-5.0.10-monolith-md-debug)