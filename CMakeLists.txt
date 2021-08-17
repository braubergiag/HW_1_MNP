cmake_minimum_required(VERSION 3.19)
project(HW_1)

SET(CMAKE_CXX_FLAGS -pthread)


set(CMAKE_CXX_STANDARD 14)

add_executable(HW_1 main.cpp NumbersHandler.cpp NumbersHandler.h csv.h)