//
// Created by ikkeg on 12/01/2021.
//
#include "graph.h"
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>


//void insert_vertices


_node* _create_node(lli priority, void *data)
{
    _node *new_node = (_node *) malloc(sizeof(_node));
//    check_malloc(new_node);

    new_node->priority = priority;
    new_node->data = data;

    return new_node;
}

HEAP *create_heap(lli size)
{
    HEAP *heap = (HEAP *) malloc(sizeof(HEAP));
//    check_malloc(heap);

    heap->size = 0;
    heap->max_size = size + 1;

    heap->data = (void **) malloc(size * sizeof (void *));
    for (int i = 1; i < size + 1; ++i)
    {
        heap->data[i] = NULL;
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

void swap_index(HEAP *h, int index_1, int index_2)
{
    ((_node *) h->data[index_1])->index = index_2;
    ((_node *) h->data[index_2])->index = index_1;
}

void swap_data(void **item_1, void **item_2)
{
    void *aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;
}

lli get_priority(HEAP *h, int index)
{
    return ((_node *) h->data[index])->priority;
}

void enqueue(HEAP *heap, lli priority, void *data)
{
    if (heap->size >= heap->max_size - 1)
    {
        printf("Heap overflow.\n");
    }
    else
    {
        _node *new_node = _create_node(priority, data);

        heap->data[++heap->size] = new_node;
        new_node->index = heap->size;


        int key_index = heap->size;

        int parent_index = get_parent_index(key_index);

        while (parent_index >= 1 && get_priority(heap, key_index) < get_priority(heap, parent_index))
        {

            swap_index(heap, parent_index, key_index);

            swap_data(&heap->data[parent_index], &heap->data[key_index]);

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

    _node *t = heap->data[i];
    _node *t_l = heap->data[left_index];
    _node *t_r = heap->data[right_index];

    if (left_index <= heap->size && t_l->priority < t->priority)
    {
        smallest = left_index;
    }
    else
    {
        smallest = i;
    }

    _node *t_s = heap->data[smallest];

    if (right_index <= heap->size && t_r->priority < t_s->priority)
    {
        smallest = right_index;
        t_s = heap->data[smallest];
    }

    if (t != t_s)
    {
        swap_index(heap, i, smallest);
        swap_data(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

void update_priority (HEAP *heap, int index, lli new_priority) {
    ((_node *) heap->data[index])->priority = new_priority;
    bubble_up(heap, index);
}

void bubble_up(HEAP *heap, int index) {
    if(index == 0) {
        return;
    }

    int parent_index = get_parent_index(index);

    if(get_priority(heap, parent_index) > get_priority(heap, index)) {
        swap_index(heap, parent_index, index);
        swap_data(&heap->data[parent_index], &heap->data[index]);
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
        _node *item = (_node *) heap->data[1];

        heap->data[1] = heap->data[heap->size];

        heap->data[heap->size] = NULL;

        heap->size -= 1;

        min_heapify(heap, 1);

        return item->data;
    }
}

void free_heap(HEAP *heap)
{
    for (int i = 1; i <= heap->size; ++i)
    {
        free((_node *) heap->data[i]);
    }

    free(heap);
}

