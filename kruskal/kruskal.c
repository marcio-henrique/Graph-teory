//
// Created by ikkeg on 12/01/2021.
//
#include "kruskal.h"
#include "heap.h"
#include "graph.h"
#include "union-find.h"
#include <stdlib.h>
#include <stdio.h>

void kruskal_algorithm (Graph *graph) {
    lli father[graph->vertex_quantity], rank[graph->vertex_quantity];

    Adjacency_list *tree = NULL;

    make_set(father, rank, graph->vertex_quantity);

    HEAP *heap = create_heap(graph->edge_quantity);
    heap_insert(heap, graph);

    while (heap->size > 0) {
        Adjacency_list *actual_edge = (Adjacency_list *) dequeue(heap);

        if(find(father, actual_edge->origin) != find(father, actual_edge->item)) {
            tree = add_node(tree, actual_edge);
            make_union(father, rank, actual_edge->origin, actual_edge->item);
        }
    }

    print_MST(tree);
}
void print_MST(Adjacency_list *tree) {
    lli total_weight = 0;
    while (tree != NULL) {
        printf("%lld %lld\n", tree->origin, tree->item);

        total_weight += tree->weight;
        tree = tree->next;
    }
    printf("Total Cost: %lld\n", total_weight);
}
void heap_insert(HEAP *heap, Graph *graph) {
    for(lli i = 0; i < graph->vertex_quantity; i++) {
        Adjacency_list *actual = graph->adjacency_list[i];
        while (actual != NULL) {
            enqueue(heap, actual->weight, actual);
            actual = actual->next;
        }

    }
}

//void kruskal_algorithm (Graph *graph, lli ) {
//
//}