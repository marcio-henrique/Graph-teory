cmake_minimum_required(VERSION 3.17)
project(kruskal C)

set(CMAKE_C_STANDARD 99)

add_executable(kruskal main.c union-find.h union-find.c heap.h heap.c graph.h graph.c kruskal.h kruskal.c)