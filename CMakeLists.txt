cmake_minimum_required(VERSION 3.30)
project(Competitive_Programming_Bible)

set(CMAKE_CXX_STANDARD 20)

add_library(Competitive_Programming_Bible STATIC library.cpp
        Math/Number_Theory/SieveOfEratosthenes.cpp)
