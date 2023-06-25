cmake_minimum_required(VERSION 3.22)

set(project "MyUniversalLibrary")
project(${project})

set(CMAKE_CXX_STANDARD 17)
option(BUILD_TESTS "Build tests" ON)

set(${project}_SOURCES
        main.cpp)

set(${project}_TESTS
        tests/test.cpp)

set(${project}_LIBRARIES
        Structures
        SortAlgorithms
        Prints
        Graphs)

add_subdirectory(${project}_LIBRARIES)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

# Testing and executing
add_executable(${project} ${project}_SOURCE_LIST)

target_link_libraries(${project}
        ${project}_LIBRARIES
        gtest
        gmock
        pthread)

