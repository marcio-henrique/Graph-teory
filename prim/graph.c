//
// Created by ikkeg on 07/01/2021.
//
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph *createGraph(int verticesQantity) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->adjacencyList = (AdjacencyList **)malloc(verticesQantity * sizeof (int*));
    graph->verticesQuantity = verticesQantity;

}

