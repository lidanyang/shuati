# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 11)

add_executable(test jianzhioffer/main.cpp jianzhioffer/main1.cpp)
add_executable(test1 jianzhioffer/main1.cpp jianzhioffer/main1.cpp)