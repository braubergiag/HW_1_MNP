cmake_minimum_required(VERSION 3.0.2)
project(HW_1)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(include)
set(CMAKE_CXX_STANDARD 14)

add_executable(HW_1 source/main.cpp source/NumbersHandler.cpp include/NumbersHandler.h)