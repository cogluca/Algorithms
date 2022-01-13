cmake_minimum_required(VERSION 3.20)
project(../../esercizio2 C)

set(CMAKE_C_STANDARD 99)

add_executable(esercizio2Base ../../esercizio2/edit_distance_test.c
        ../../esercizio2/edit_distance_strings.h
        ../../esercizio2/edit_distance_strings.c
        ../../esercizio2/unity.c
        ../../esercizio2/unity.h
        ../../esercizio2/unity_internals.h)


add_executable(esercizio2DynTest ../../esercizio2/edit_distance_strings_dynamic.c
        ../../esercizio2/edit_distance_strings_dynamic.h
        ../../esercizio2/edit_distance_dyn_test.c
        ../../esercizio2/unity.c
        ../../esercizio2/unity.h
        ../../esercizio2/unity_internals.h)

add_executable(esercizio2Dataset ../../esercizio2/edit_distance_strings_dynamic.c
        ../../esercizio2/edit_distance_strings_dynamic.h
        ../../esercizio2/edit_distance_strings_main.c)
