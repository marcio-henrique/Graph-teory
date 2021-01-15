//
// Created by MichelT on 15/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"


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