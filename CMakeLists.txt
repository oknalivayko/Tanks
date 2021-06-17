cmake_minimum_required(VERSION 3.10)

project(Tanks)

add_executable(Tanks tanks.cpp)

set_target_properties(
    Tanks PROPERTIES
    CXX_STANDART 11
    CXX_STANDART_REQUIRED ON
)
