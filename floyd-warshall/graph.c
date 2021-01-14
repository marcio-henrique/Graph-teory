//
// Created by ikkeg on 07/01/2021.
//
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

Graph *create_graph(lli vertex_quantity) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertex_quantity = vertex_quantity;

    graph->adjacency_matrix = create_adjacency_matrix(vertex_quantity);

    return graph;
}

lli **create_adjacency_matrix(lli vertex_quantity) {
    lli **new_adjacency_matrix = (lli **) malloc(vertex_quantity * sizeof (lli *));
    for(lli i = 0; i < vertex_quantity; i++) {
        new_adjacency_matrix[i] = (lli *) malloc(vertex_quantity * (sizeof (lli)));
        for(lli j = 0; j < vertex_quantity; j++) {
            if (i == j) {
                new_adjacency_matrix[i][j] = 0;
            } else {
                new_adjacency_matrix[i][j] = LLONG_MAX;
            }
        }
    }
    return new_adjacency_matrix;
}

Graph *add_weighted_simple_edge (Graph *graph, lli vertex1, lli vertex2, lli weight) {
    graph->adjacency_matrix[vertex1][vertex2] = weight;
    graph->adjacency_matrix[vertex2][vertex1] = weight;

    return graph;
}

Graph *add_one_directed_edge (Graph *graph, lli vertex1, lli vertex2, lli weight) {
    graph->adjacency_matrix[vertex1][vertex2] = weight;

    return graph;
}