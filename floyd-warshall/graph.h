//
// Created by ikkeg on 07/01/2021.
//

#ifndef FLOYD_WARSHALL_GRAPH_H
#define FLOYD_WARSHALL_GRAPH_H

typedef long long int lli;

typedef struct Graph Graph;

struct Graph
{
    lli **adjacency_matrix;
    lli vertex_quantity;
};

Graph *create_graph(lli vertex_quantity);

lli **create_adjacency_matrix(lli vertex_quantity);

Graph *add_one_directed_edge (Graph *graph, lli vertex1, lli vertex2, lli weight);

#endif //FLOYD_WARSHALL_GRAPH_H
