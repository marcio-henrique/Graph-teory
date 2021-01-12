//
// Created by ikkeg on 09/01/2021.
//
#include <stdio.h>
#include "graph.h"
#include "prim.h"
#include "heap.h"
//
//struct Graph *initialize_father(Graph * graph) {
//    for (int i = 0; i < graph->vertices_quantity; i++) {
//        graph->father[i] = -1;
//    }
//    return graph;
//}
//Graph *prim_algorithm (Graph *graph, int vertice_origin) {
//    graph = initialize_father(graph);
//
//    graph->father[vertice_origin] = vertice_origin;
//
//    while (1) {
//        int min_weight = INT_MAX, destiny;
//        for(int i = 0; i < graph->vertices_quantity; i++) {
//
//            if (graph->father[i] != -1) {
//                Adjacency_list *actual = graph->adjacency_list[i];
//                while(actual != NULL) {
//                    if (actual->weight < min_weight) {
//                        min_weight = actual->weight;
//                        vertice_origin = i;
//                        destiny = actual->item;
//                    }
//
//                    actual = actual->next;
//                }
//            }
//        }
//        if (min_weight == INT_MAX) {
//            break;
//        }
//
//        graph->father[destiny] = vertice_origin;
//    }
//    return graph;
//}

Graph *prim_algorithm (Graph *graph, lli vertice_origin) {
    Vertex **vertex = graph->vertex;
    vertex[vertice_origin]->cost = 0;
    vertex[vertice_origin]->previous = vertice_origin;

    HEAP *heap = create_heap(graph->vertex_quantity, vertex);

    while (heap->size > 0) {
        Vertex *actual = dequeue(heap);
        actual->visited = 1;
        Adjacency_list *node = actual->adjacency_list;

        while (node != NULL) {          //enquanto houverem vizinhos
            Vertex *neighbor = vertex[node->item];
            if (neighbor->visited == 0) {         //se não foi visitado
                if (neighbor->cost > node->weight) {     //se o custo do vizinho é maior que o peso da aresta entre eles
                    neighbor->cost = node->weight;
                    neighbor->previous = actual->index;

                    bubble_up(heap, neighbor->index_heap);
                }
            }
            node = node->next;
        }
    }
    return graph;
}

void print_MST(Vertex **vertex, lli size) {
    lli total_cost = 0;
    for (lli i = 0; i < size; i++) {
        if(vertex[i]->index != vertex[i]->previous) {
            printf("%lld %lld\n", vertex[i]->index, vertex[i]->previous);
        }
        total_cost += vertex[i]->cost;
    }
    printf("Total Cost: %lld\n", total_cost);
}


