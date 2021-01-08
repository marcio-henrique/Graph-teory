cmake_minimum_required(VERSION 3.17)
project(prim C)

set(CMAKE_C_STANDARD 99)

add_executable(prim main.c graph.h graph.c)