cmake_minimum_required(VERSION 3.3)
project(OR_gate_implementation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(OR_gate_implementation ${SOURCE_FILES})