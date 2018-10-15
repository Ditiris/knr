cmake_minimum_required(VERSION 3.6)
project(knr)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)
add_subdirectory(ch01)
