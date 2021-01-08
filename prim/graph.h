//
// Created by ikkeg on 07/01/2021.
//

#ifndef PRIM_GRAPH_H
#define PRIM_GRAPH_H

#define MAX_VALUE 1000
typedef struct Graph Graph;
typedef struct AdjacencyList AdjacencyList;
struct AdjacencyList
{
    int position;
    int weight;
    AdjacencyList *next;
};
struct Graph
{
    struct AdjacencyList **adjacencyList;
    int verticesQuantity;

};

Graph *createGraph(int verticesQantity);
#endif //PRIM_GRAPH_H
