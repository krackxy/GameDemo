cmake_minimum_required(VERSION 4.1)
project(GameDemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameDemo main.cpp
        include/attacks.h
        include/battles.h
        include/classes.h
        include/monsters.h
        src/attacks.cpp
        src/battles.cpp
        src/classes.cpp
)
