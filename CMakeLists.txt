cmake_minimum_required(VERSION 3.14..3.20)
project(HW_1  LANGUAGES CXX C)

set(CMAKE_VERBOSE_MAKEFILE ON CMAKE_CXX_FLAGS -pthread)

include(FetchContent)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git)
FetchContent_MakeAvailable(googletest)

include_directories(include)
set(CMAKE_CXX_STANDARD 14)

add_executable(HW_1 source/main.cpp source/NumbersHandler.cpp include/NumbersHandler.h)
target_link_libraries(HW_1 PRIVATE gtest)