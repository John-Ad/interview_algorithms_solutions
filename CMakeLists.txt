# Specify the minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(interview_solutions VERSION 1.0)

# Request C++ 19 standard features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# for coc
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable(main ./src/main.cpp ./src/LinkedList.cpp ./src/ArrayQuestions.cpp ./src/Trees.cpp)

set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")



