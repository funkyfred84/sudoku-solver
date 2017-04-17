cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Sudoku-Solver)

set(CMAKE_SOURCE_DIR src)
set(CMAKE_BINARY_DIR bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(TEST_DIR test)

add_executable(sudoku-solver ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/backtrackingtree.cpp ${CMAKE_SOURCE_DIR}/sudoku.cpp)

add_executable(sudoku_test ${TEST_DIR}/sudoku_test.cpp ${CMAKE_SOURCE_DIR}/sudoku.cpp)
target_link_libraries(sudoku_test ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
