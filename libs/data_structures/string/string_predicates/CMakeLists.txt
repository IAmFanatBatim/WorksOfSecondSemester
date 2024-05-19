cmake_minimum_required(VERSION 3.26)
project(string_predicates C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(string_predicates
        string_predicates.c
        string_predicates.h)
