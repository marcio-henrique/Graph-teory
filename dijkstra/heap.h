//
// Created by MichelT on 15/01/2021.
//

#ifndef DIJKSTRA_HEAP_H
#define DIJKSTRA_HEAP_H

#include "graph.h"

typedef struct HEAP HEAP;
struct HEAP {
    lli size;
    lli max_size;
    struct Vertex **vertex;

};

HEAP *create_heap(int size, Vertex **vertex_list);

int get_parent_index(int i);

int get_left_index(int i);

int get_right_index(int i);

void swap_vertex(void **item_1, void **item_2);

lli get_cost(HEAP *h, int index);

void enqueue(HEAP *heap, Vertex *newVertex);

void min_heapify(HEAP *heap, int i);

void bubble_up(HEAP *heap, int i);

void *dequeue(HEAP *heap);

void free_heap(HEAP *heap);


#endif //DIJKSTRA_HEAP_H
