//
// Created by ikkeg on 11/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"



HEAP *create_heap(int size, Vertex **vertex_list)
{
    HEAP *heap = (HEAP *) malloc(sizeof(HEAP));
    //check_malloc(heap);

    heap->vertex = (Vertex **) malloc((size + 1) * sizeof (Vertex *));

    heap->size = 0;
    heap->max_size = size + 1;

    for (int i = 0; i < size; ++i)
    {
        enqueue(heap, vertex_list[i]);
    }

    return heap;
}

int get_parent_index(int i)
{
    return (i / 2);
}

int get_left_index(int i)
{
    return (2 * i);
}

int get_right_index(int i)
{
    return (2 * i + 1);
}

void swap_vertex(void **item_1, void **item_2)
{
    void *aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;
}

lli get_cost(HEAP *h, int index)
{
    return ((Vertex *) h->vertex[index])->cost;
}

void enqueue(HEAP *heap, Vertex *newVertex)
{
    if (heap->size >= heap->max_size - 1)
    {
        printf("Heap overflow.\n");
    }
    else
    {
        heap->vertex[++heap->size] = newVertex;
        newVertex->index_heap = heap->size;


        int key_index = heap->size;

        int parent_index = get_parent_index(key_index);

        while (parent_index >= 1 && get_cost(heap, key_index) < get_cost(heap, parent_index))
        {
            heap->vertex[parent_index]->index_heap = key_index;
            heap->vertex[key_index]->index_heap = parent_index;
            swap_vertex((void *) &heap->vertex[parent_index], (void *) &heap->vertex[key_index]);

            key_index = parent_index;

            parent_index = get_parent_index(key_index);
        }
    }
}

void min_heapify(HEAP *heap, int i)
{
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    Vertex *t = heap->vertex[i];
    Vertex *t_l = heap->vertex[left_index];
    Vertex *t_r = heap->vertex[right_index];

    if (left_index <= heap->size && t_l->cost < t->cost)
    {
        smallest = left_index;
    }
    else
    {
        smallest = i;
    }

    Vertex *t_s = heap->vertex[smallest];

    if (right_index <= heap->size && t_r->cost < t_s->cost)
    {
        smallest = right_index;
        t_s = heap->vertex[smallest];
    }

    if (t != t_s)
    {
        heap->vertex[i]->index_heap = smallest;
        heap->vertex[smallest]->index_heap = i;
        swap_vertex((void *) &heap->vertex[i], (void *) &heap->vertex[smallest]);
        min_heapify(heap, smallest);
    }
}

void bubble_up(HEAP *heap, int i) {
    if(i == 0) {
        return;
    }

    int parent_index = get_parent_index(i);
    if(heap->vertex[parent_index]->cost > heap->vertex[i]->cost) {
        heap->vertex[parent_index]->index_heap = i;
        heap->vertex[i]->index_heap = parent_index;
        swap_vertex((void *) &heap->vertex[parent_index], (void *) &heap->vertex[i]);
        bubble_up(heap, parent_index);
    }
}

void *dequeue(HEAP *heap)
{
    if (!(heap->size))
    {
        printf("Heap underflow.\n");
        return NULL;
    }
    else
    {
        Vertex *item = (Vertex *) heap->vertex[1];

        heap->vertex[1] = heap->vertex[heap->size];
        heap->vertex[1]->index_heap = 1;

        heap->vertex[heap->size] = NULL;

        heap->size -= 1;

        min_heapify(heap, 1);

        return item;
    }
}

void free_heap(HEAP *heap)
{
    for (int i = 1; i <= heap->size; ++i)
    {
        free((Vertex *) heap->vertex[i]);
    }

    free(heap);
}
