//
// Created by ikkeg on 13/01/2021.
//

#include "floyd_warshall.h"
#include <stdio.h>
#include <limits.h>

void floyd_warshall_algorithm (Graph *graph) {
    lli minimal_distancies[graph->vertex_quantity][graph->vertex_quantity];

//    initialize_distancies(graph->adjacency_matrix, (lli **) minimal_distancies, graph->vertex_quantity);
    for (lli i = 0; i < graph->vertex_quantity; i++) {
        for (lli j = 0; j < graph->vertex_quantity; j++) {
            minimal_distancies[i][j] = graph->adjacency_matrix[i][j];
        }
    }

    for (lli k = 0; k < graph->vertex_quantity; k++) {
        for (lli i = 0; i < graph->vertex_quantity; i++) {
            for (lli j = 0; j < graph->vertex_quantity; j++) {
                minimal_distancies[i][j] = min(minimal_distancies[i][j], minimal_distancies[i][k] + minimal_distancies[k][j]);
            }
        }
    }
//    printMatrix((lli **) minimal_distancies, graph->vertex_quantity);

    for (lli i = 0; i < graph->vertex_quantity; i++) {
        for (lli j = 0; j < graph->vertex_quantity; j++) {
            if (minimal_distancies[i][j] == LLONG_MAX) {
                printf("INF.\t");
            } else {
                printf("%lld\t", minimal_distancies[i][j]);
            }
        }
        printf("\n");
    }
}

lli min(lli a, lli b) {
    return a < b ? a : b;
}

void initialize_distancies(lli **adjacency_matrix, lli **minimal_distancies, lli size) {
    for (lli i = 0; i < size; i++) {
        for (lli j = 0; j < size; j++) {
            minimal_distancies[i][j] = adjacency_matrix[i][j];
        }
    }
};

void printMatrix(lli **matrix, lli size) {
    for (lli i = 0; i < size; i++) {
        for (lli j = 0; j < size; j++) {
            if (matrix[i][j] == LLONG_MAX) {
                printf("INF.\t");
            } else {
                printf("%lld\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}