cmake_minimum_required(VERSION 3.22)

project(SortAlgorithms)
set(project "SortAlgorithms")

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        sorts.cpp
        sequence.cpp
        )

set(${project}_HEADERS
        sorts.h
        sequence.h
        )

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
            STATIC
            ${${project}_SOURCE_LIST})