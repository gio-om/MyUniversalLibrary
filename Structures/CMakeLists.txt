cmake_minimum_required(VERSION 3.22)

set(project "Structures")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        MyVector.cpp
        BinaryTree.cpp
        )

set(${project}_HEADERS
        MyVector.h
        BinaryTree.h
        )

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})