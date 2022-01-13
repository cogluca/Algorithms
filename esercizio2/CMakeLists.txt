cmake_minimum_required(VERSION 3.20)
project(. C)

set(CMAKE_C_STANDARD 99)

add_executable(esercizio2Base edit_distance_test.c
        edit_distance_strings.h
        edit_distance_strings.c
        unity.c
        unity.h
        unity_internals.h)


add_executable(esercizio2DynTest edit_distance_strings_dynamic.c
        edit_distance_strings_dynamic.h
        edit_distance_dyn_test.c
        unity.c
        unity.h
        unity_internals.h)

add_executable(esercizio2Dataset edit_distance_strings_dynamic.c
        edit_distance_strings_dynamic.h
        edit_distance_strings_main.c)
