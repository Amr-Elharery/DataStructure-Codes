cmake_minimum_required(VERSION 3.23)
project(examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        selection
        selection-sort.cpp
)
add_executable(
        quick
        quick-sort.cpp
)
add_executable(
        bubble
        bubble-sort.cpp
)
add_executable(
        insertion
        insertion-sort.cpp
)
add_executable(
        merge
        merge-sort.cpp
)

add_executable(
        linked-list
        linked-list.cpp
)

add_executable(
        double-linked-list
        double-linked-list.cpp
)
add_executable(
        circular-linked-list
        circular-linked-list.cpp
)

add_executable(
        heap
        heap.cpp
)
add_executable(
        BST
        binary-search-tree.cpp
)
