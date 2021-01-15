cmake_minimum_required(VERSION 3.17)
project(dijkstra C)

set(CMAKE_C_STANDARD 99)

add_executable(dijkstra main.c graph.h heap.h heap.c graph.c dijkstra.h dijkstra.c)