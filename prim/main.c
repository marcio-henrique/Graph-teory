#include <stdio.h>
#include "graph.h"
#include "prim.h"
int main() {
    Graph *graph = create_graph(6);
    graph = add_weighted_simple_edge(graph, 0, 1, 5);
    graph = add_weighted_simple_edge(graph, 0, 2, 6);
    graph = add_weighted_simple_edge(graph, 0, 3, 4);
    graph = add_weighted_simple_edge(graph, 1, 2, 1);
    graph = add_weighted_simple_edge(graph, 1, 3, 2);
    graph = add_weighted_simple_edge(graph, 2, 3, 2);
    graph = add_weighted_simple_edge(graph, 2, 4, 7);
    graph = add_weighted_simple_edge(graph, 2, 5, 3);
    graph = add_weighted_simple_edge(graph, 3, 5, 4);
    graph = add_weighted_simple_edge(graph, 4, 5, 4);

    graph = prim_algorithm(graph, 0);
    print_MST(graph->vertex, graph->vertex_quantity);

    return 0;
}
