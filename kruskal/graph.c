//
// Created by ikkeg on 07/01/2021.
//
#include <stdlib.h>
#include "graph.h"

Graph *create_graph(lli vertex_quantity) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertex_quantity = vertex_quantity;
    graph->edge_quantity = 0;

    graph->adjacency_list = create_adjacency_list(vertex_quantity);

    return graph;
}

Adjacency_list **create_adjacency_list(lli vertex_quantity) {
    Adjacency_list **new_adjacency_list = (Adjacency_list **) malloc(vertex_quantity * sizeof (Adjacency_list *));
    for(lli i = 0; i < vertex_quantity; i++) {
        new_adjacency_list[i] = NULL;
    }
    return new_adjacency_list;
}

Adjacency_list *create_node(lli origin, lli item, lli weight) {
    Adjacency_list *new_node = (Adjacency_list *) malloc(sizeof(Adjacency_list));
    new_node->origin = origin;
    new_node->item = item;
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}

Adjacency_list* begin_add(Adjacency_list *head, lli origin, lli item, lli weight) {
    Adjacency_list *new_node = create_node(origin, item, weight);
    new_node->next = head;
    head = new_node;

    return head;
}

Adjacency_list* add_node(Adjacency_list *head, Adjacency_list *new_node) {
    new_node->next = head;
    head = new_node;

    return head;
}

Graph *add_weighted_simple_edge (Graph *graph, lli vertex1, lli vertex2, lli weight) {

    graph->adjacency_list[vertex1] = begin_add(graph->adjacency_list[vertex1], vertex1, vertex2, weight);
    graph->adjacency_list[vertex2] = begin_add(graph->adjacency_list[vertex2], vertex2, vertex1, weight);
    graph->edge_quantity++;
    return graph;
}

Graph *add_one_directed_edge (Graph *graph, lli vertex1, lli vertex2, lli weight) {
    graph->adjacency_list[vertex1] = begin_add(graph->adjacency_list[vertex1], vertex1, vertex2, weight);
    graph->edge_quantity++;
    return graph;
}