cmake_minimum_required(VERSION 3.22)

set(project "MyUniversalLibrary")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(Structures)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST} Structures)

target_link_libraries(${project} Structures)
