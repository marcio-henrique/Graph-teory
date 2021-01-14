//
// Created by ikkeg on 13/01/2021.
//

#include "floyd_warshall.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void floyd_warshall_algorithm (Graph *graph) {
    lli **minimal_distancies;

    minimal_distancies = initialize_distancies(graph->adjacency_matrix, graph->vertex_quantity);

    for (lli k = 0; k < graph->vertex_quantity; k++) {
        for (lli i = 0; i < graph->vertex_quantity; i++) {
            for (lli j = 0; j < graph->vertex_quantity; j++) {
                if (minimal_distancies[i][k] != LLONG_MAX && minimal_distancies[k][j] != LLONG_MAX) {
                    minimal_distancies[i][j] = min(minimal_distancies[i][j], minimal_distancies[i][k] + minimal_distancies[k][j]);
                }
            }
        }
    }
    printMatrix(minimal_distancies, graph->vertex_quantity);

}

lli min(lli a, lli b) {
    return a < b ? a : b;
}

lli **initialize_distancies(lli **adjacency_matrix, lli size) {
    lli **minimal_distancies = (lli **) malloc(size * sizeof (lli *));
    for (lli i = 0; i < size; i++) {
        minimal_distancies[i] = (lli *) malloc(size * (sizeof (lli)));
        for (lli j = 0; j < size; j++) {
            minimal_distancies[i][j] = adjacency_matrix[i][j];
        }
    }

    return minimal_distancies;
};

void printMatrix(lli **minimal_distancies, lli size) {
    for (lli i = 0; i < size; i++) {
        for (lli j = 0; j < size; j++) {
            if (minimal_distancies[i][j] == LLONG_MAX) {
                printf("INF.\t");
            } else {
                printf("%lld\t", minimal_distancies[i][j]);
            }
        }
        printf("\n");
    }
}