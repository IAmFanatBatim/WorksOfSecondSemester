cmake_minimum_required(VERSION 3.16)
project(WorksOfSecondSemester C)

set(CMAKE_C_STANDARD 11)
add_executable(WorksOfSecondSemester main.c)

add_subdirectory(libs)
target_link_libraries(WorksOfSecondSemester data_structures)
target_link_libraries(WorksOfSecondSemester algorithms)