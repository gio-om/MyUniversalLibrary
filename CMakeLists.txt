cmake_minimum_required(VERSION 3.22)

set(project "MyUniversalLibrary")
project(${project})

set(CMAKE_CXX_STANDARD 17)
option(BUILD_TESTS "Build tests" ON)

set(${project}_SOURCES
        main.cpp)

set(${project}_TESTS
        tests/test.cpp)

add_subdirectory(Structures tests)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

# Testing and executing
add_executable(tests
    ${${project}_SOURCE_LIST}
        Structures
        ${project}_TESTS)

target_link_libraries(tests ${project}
        Structures
        GTest::gtest_main)
enable_testing()
add_test(NAME unit_tests COMMAND tests)
