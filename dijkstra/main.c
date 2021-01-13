#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_VAlUE 1000
typedef struct Adjacency_list Adjacency_list;
typedef struct Vertex Vertex;
typedef struct Graph Graph;
typedef long long int lli;

struct Adjacency_list
{
    lli item;
    lli weight;
    Adjacency_list *next;
};

struct Vertex
{
    lli index;
    lli index_heap;
    lli cost;
    lli previous;
    int visited;

    Adjacency_list *adjacency_list;
};
struct Graph
{
    Vertex **vertex;
    lli vertex_quantity;
};

Vertex *create_vertex(lli index);

Graph *create_graph(lli vertex_quantity);

Graph *add_weighted_simple_edge (Graph *graph, lli vertex1, lli vertex2, lli weight);

Adjacency_list *create_node(lli item, lli weight);

Adjacency_list* begin_add(Adjacency_list *head, lli item, lli weight);



Vertex *create_vertex(lli index) {
    Vertex *new_vertex = (Vertex *) malloc(sizeof(Vertex));
    new_vertex->index = index;
    new_vertex->previous = -1;
    new_vertex->visited = 0;
    new_vertex->cost = LLONG_MAX;
    new_vertex->adjacency_list = NULL;

    return  new_vertex;
}

Graph *create_graph(lli vertex_quantity) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertex_quantity = vertex_quantity;

    graph->vertex = (Vertex **) malloc(vertex_quantity * sizeof (Vertex *));
    for(lli i = 0; i < vertex_quantity; i++) {
        graph->vertex[i] = create_vertex(i);
    }

    return graph;
}


Adjacency_list *create_node(lli item, lli weight) {
    Adjacency_list *new_adjacency_list = (Adjacency_list *) malloc(sizeof(Adjacency_list));
    new_adjacency_list->item = item;
    new_adjacency_list->weight = weight;
    new_adjacency_list->next = NULL;

    return new_adjacency_list;
}


Adjacency_list* begin_add(Adjacency_list *head, lli item, lli weight)
{
    Adjacency_list *new_node = create_node(item, weight);
    new_node->next = head;
    head = new_node;

    return head;
}

Graph *add_weighted_simple_edge (Graph *graph, lli vertex1, lli vertex2, lli weight) {

    graph->vertex[vertex1]->adjacency_list = begin_add(graph->vertex[vertex1]->adjacency_list, vertex2, weight);
    graph->vertex[vertex2]->adjacency_list = begin_add(graph->vertex[vertex2]->adjacency_list, vertex1, weight);

    return graph;
}


/******************************************************************************/


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
    if(i == 1) {
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

/******************************************************************************/

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

int main() {

    int n = 9;
    Graph *graph = create_graph(n);
    graph = add_weighted_simple_edge(graph, 0, 1, 1);
    graph = add_weighted_simple_edge(graph, 0, 2, 1);
    graph = add_weighted_simple_edge(graph, 0, 5, 3);
    graph = add_weighted_simple_edge(graph, 1, 4, 3);
    graph = add_weighted_simple_edge(graph, 2, 3, 2);
    graph = add_weighted_simple_edge(graph, 3, 4, 4);
    graph = add_weighted_simple_edge(graph, 3, 7, 1);
    graph = add_weighted_simple_edge(graph, 4, 6, 3);
    graph = add_weighted_simple_edge(graph, 5, 8, 2);
    graph = add_weighted_simple_edge(graph, 6, 8, 1);
    graph = add_weighted_simple_edge(graph, 7, 8, 3);


    graph = dijkstra(graph,0);

    printf("Distance: %lld\nPrevious: %lld", graph->vertex[graph->vertex_quantity - 1]->cost,
           graph->vertex[graph->vertex_quantity - 1]->previous);

    return 0;
}
