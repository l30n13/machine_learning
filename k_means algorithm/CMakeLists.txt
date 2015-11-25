cmake_minimum_required(VERSION 3.3)
project(k_means_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(k_means_algorithm ${SOURCE_FILES})