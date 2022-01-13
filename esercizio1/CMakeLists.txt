cmake_minimum_required(VERSION 3.20)
project(../esercizio1 C)

set(CMAKE_C_STANDARD 99)

add_executable(executable test_merge_binaryinsertion_sort.c
        merge_binary_insertion_sort.c
        merge_binary_insertion_sort.h
        unity.c
        unity.h
        unity_internals.h)


add_executable(executableWithDataset
        merge_binary_insertion_sort.c
        merge_binary_insertion_sort.h
        merge_binary_insertion_sort_main.c)
