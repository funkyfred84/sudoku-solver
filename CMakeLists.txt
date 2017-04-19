cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME_STR sudoku)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Project title and define versioning
project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Include paths
set(SUDOKU_INCLUDES ${SUDOKU_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/sudoku)

# Gather the header and source files
#file(GLOB_RECURSE INC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
#file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.h)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Build object files for reuse (e.g. in test)
#ADD_LIBRARY(demo_objects OBJECT ${INC_FILES} ${SRC_FILES})

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Unit tests
add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Build
#set(SOURCE_FILES src/main.cpp $<TARGET_OBJECTS:demo_objects>)
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(sudoku-solver ${SOURCE_FILES})
target_link_libraries(sudoku-solver ${Boost_LIBRARIES})
