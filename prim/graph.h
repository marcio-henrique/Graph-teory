//
// Created by ikkeg on 07/01/2021.
//

#ifndef PRIM_GRAPH_H
#define PRIM_GRAPH_H

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
#endif //PRIM_GRAPH_H
