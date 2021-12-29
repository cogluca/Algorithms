cmake_minimum_required(VERSION 3.20)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 test_merge_binaryinsertion_sort.c
        merge_binary_insertion_sort.c
        merge_binary_insertion_sort.h
        unity.c
        unity.h
        unity_internals.h)
