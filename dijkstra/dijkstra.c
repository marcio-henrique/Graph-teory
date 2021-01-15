//
// Created by MichelT on 15/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "heap.h"


Graph* dijkstra(Graph *graph , int source) {
    Vertex **vertex = graph->vertex;
    vertex[source]->cost = 0;
    vertex[source]->previous = source;

    HEAP *heap = create_heap(graph->vertex_quantity, vertex);

    while (heap->size > 0) {
        Vertex *actual = dequeue(heap);
        actual->visited = 1;
        Adjacency_list *node = actual->adjacency_list;

        while (node != NULL) {          // enquanto houverem vizinhos
            Vertex *neighbor = vertex[node->item];
            if (neighbor->visited == 0) {         // se não foi visitado
                if (neighbor->cost > actual->cost + node->weight) {     // se o custo do vizinho é maior que o custo do
                                                                        // vértice atual e o peso da aresta entre eles

                    neighbor->cost = actual->cost + node->weight;
                    neighbor->previous = actual->index;

                    bubble_up(heap, neighbor->index_heap);
                }
            }
            node = node->next;
        }
    }
    return graph;
}