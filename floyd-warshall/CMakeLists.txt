cmake_minimum_required(VERSION 3.17)
project(floyd_warshall C)

set(CMAKE_C_STANDARD 99)

add_executable(floyd_warshall main.c floyd_warshall.c floyd_warshall.h graph.h graph.c)