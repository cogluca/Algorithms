cmake_minimum_required(VERSION 3.20)
project(Algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(esercizio2Base edit_distance/edit_distance_test.c
        edit_distance/edit_distance_strings.h
        edit_distance/edit_distance_strings.c
        edit_distance/unity.c
        edit_distance/unity.h
        edit_distance/unity_internals.h)


add_executable(esercizio2DynTest edit_distance/edit_distance_strings_dynamic.c
        edit_distance/edit_distance_strings_dynamic.h
        edit_distance/edit_distance_dyn_test.c
        edit_distance/unity.c
        edit_distance/unity.h
        edit_distance/unity_internals.h)

add_executable(esercizio2Dataset edit_distance/edit_distance_strings_dynamic.c
        edit_distance/edit_distance_strings_dynamic.h
        edit_distance/edit_distance_strings_main.c)

add_executable(merge_binary_insertion_sort_basicTest merge_binary_insertion_sort/test_merge_binaryinsertion_sort.c
        merge_binary_insertion_sort/merge_binary_insertion_sort.c
        merge_binary_insertion_sort/merge_binary_insertion_sort.h
        merge_binary_insertion_sort/unity.c
        merge_binary_insertion_sort/unity.h
        merge_binary_insertion_sort/unity_internals.h)


add_executable(merge_binary_insertion_sort_executableWithDataset
        merge_binary_insertion_sort/merge_binary_insertion_sort.c
        merge_binary_insertion_sort/merge_binary_insertion_sort.h
        merge_binary_insertion_sort/merge_binary_insertion_sort_main.c)
