#include <stdio.h>
#include "graph.h"
#include "kruskal.h"
int main() {
    Graph *graph = create_graph(6);
    graph = add_one_directed_edge(graph, 0, 1, 5);
    graph = add_one_directed_edge(graph, 0, 2, 6);
    graph = add_one_directed_edge(graph, 0, 3, 4);
    graph = add_one_directed_edge(graph, 1, 2, 1);
    graph = add_one_directed_edge(graph, 1, 3, 2);
    graph = add_one_directed_edge(graph, 2, 3, 2);
    graph = add_one_directed_edge(graph, 2, 4, 7);
    graph = add_one_directed_edge(graph, 2, 5, 3);
    graph = add_one_directed_edge(graph, 3, 5, 4);
    graph = add_one_directed_edge(graph, 4, 5, 4);

    kruskal_algorithm(graph);

    return 0;
}
