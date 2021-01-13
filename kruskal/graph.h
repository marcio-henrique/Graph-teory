//
// Created by ikkeg on 07/01/2021.
//

#ifndef PRIM_GRAPH_H
#define PRIM_GRAPH_H

typedef long long int lli;

typedef struct Adjacency_list Adjacency_list;
typedef struct Vertex Vertex;
typedef struct Graph Graph;


struct Adjacency_list
{
    lli origin;
    lli item;
    lli weight;
    Adjacency_list *next;
};

struct Graph
{
    struct Adjacency_list **adjacency_list;
    lli vertex_quantity;
    lli edge_quantity;
};

Vertex *create_vertex(lli index);

Graph *create_graph(lli vertex_quantity);

Adjacency_list **create_adjacency_list(lli vertex_quantity);

Graph *add_weighted_simple_edge (Graph *graph, lli vertex1, lli vertex2, lli weight);

Graph *add_one_directed_edge (Graph *graph, lli vertex1, lli vertex2, lli weight);

Adjacency_list *create_node(lli origin, lli item, lli weight);

Adjacency_list* add_node(Adjacency_list *head, Adjacency_list *new_node);

Adjacency_list* begin_add(Adjacency_list *head, lli origin, lli item, lli weight);
#endif //PRIM_GRAPH_H
