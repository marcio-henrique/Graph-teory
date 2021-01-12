//
// Created by ikkeg on 12/01/2021.
//

#ifndef KRUSKAL_HEAP_H
#define KRUSKAL_HEAP_H

typedef long long int lli;

typedef struct HEAP HEAP;
struct HEAP {
    lli size;
    lli max_size;
    void **data;
};

/** Nó auxiliar **/
typedef struct _node {
    lli priority;
    lli index;
    void *data;
} _node;

_node* _create_node(lli priority, void *data);

HEAP *create_heap(lli size, void **data);

int get_parent_index(int i);

int get_left_index(int i);

int get_right_index(int i);

void swap_data(void **item_1, void **item_2);


void swap_index(HEAP *h, int index_1, int index_2);

void enqueue(HEAP *heap, lli priority, void *data);

void min_heapify(HEAP *heap, int i);

void bubble_up(HEAP *heap, int index);

void update_priority (HEAP *heap, int index, lli new_priority);

void* dequeue(HEAP *heap);

void free_heap(HEAP *heap);

#endif //KRUSKAL_HEAP_H
