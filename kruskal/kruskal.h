//
// Created by ikkeg on 12/01/2021.
//

#ifndef KRUSKAL_KRUSKAL_H
#define KRUSKAL_KRUSKAL_H
#include "heap.h"
#include "graph.h"

void heap_insert(HEAP *heap, Graph *graph);
void kruskal_algorithm (Graph *graph);
void print_MST(Adjacency_list *tree);
#endif //KRUSKAL_KRUSKAL_H
