cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c Include.h)
target_link_libraries(PROJET -lmingw32 -lallegro-5.0.10-monolith-md-debug)