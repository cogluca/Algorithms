cmake_minimum_required(VERSION 3.20)
project(esercizio1 C)

set(CMAKE_C_STANDARD 99)

add_executable(executable esercizio1/test_merge_binaryinsertion_sort.c
        esercizio1/merge_binary_insertion_sort.c
        esercizio1/merge_binary_insertion_sort.h
        esercizio1/unity.c
        esercizio1/unity.h
        esercizio1/unity_internals.h)


add_executable(esercizio1 esercizio1/merge_binary_insertion_sort.c
        esercizio1/merge_binary_insertion_sort.h
        esercizio1/merge_binary_insertion_sort_main.c)
