//
// Created by ikkeg on 13/01/2021.
//

#ifndef FLOYD_WARSHALL_FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_FLOYD_WARSHALL_H
#include "graph.h"

lli **initialize_distancies(lli **adjacency_matrix, lli size);
lli min(lli a, lli b);
void floyd_warshall_algorithm (Graph *graph);
void printMatrix(lli **minimal_distancies, lli size);

#endif //FLOYD_WARSHALL_FLOYD_WARSHALL_H
