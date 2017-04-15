cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Sudoku-Solver)

set(CMAKE_SOURCE_DIR src)
set(CMAKE_BINARY_DIR bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_BINARY_DIR})
message(${EXECUTABLE_OUTPUT_PATH})
message(${LIBRARY_OUTPUT_PATH})

add_executable(sudoku-solver ${CMAKE_SOURCE_DIR}/main.cpp)
