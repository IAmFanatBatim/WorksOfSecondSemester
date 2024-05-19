cmake_minimum_required(VERSION 3.26)
project(string_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_library(string_ string_.c)
