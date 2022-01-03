cmake_minimum_required(VERSION 3.20)
project(esercizio2 C)

set(CMAKE_C_STANDARD 99)

add_executable(esercizio2Base esercizio2/edit_distance_test.c
        esercizio2/edit_distance_strings.h
        esercizio2/edit_distance_strings.c)
