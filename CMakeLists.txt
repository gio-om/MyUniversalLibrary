cmake_minimum_required(VERSION 3.22)

project(MyUniversalLibrary)
set(project "MyUniversalLibrary")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(SortAlgorithms)

add_executable(${project} main.cpp)

target_link_libraries(${project} SortAlgorithms)
