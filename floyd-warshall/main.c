#include <stdio.h>
#include "graph.h"
#include "floyd_warshall.h"
int main() {
    Graph *graph = create_graph(9);
//    graph = add_one_directed_edge(graph, 0, 1, 1);
//    graph = add_one_directed_edge(graph, 0, 2, 1);
//    graph = add_one_directed_edge(graph, 0, 5, 3);
//    graph = add_one_directed_edge(graph, 1, 4, 3);
//    graph = add_one_directed_edge(graph, 2, 3, 2);
//    graph = add_one_directed_edge(graph, 3, 4, 4);
//    graph = add_one_directed_edge(graph, 3, 7, 1);
//    graph = add_one_directed_edge(graph, 4, 6, 3);
//    graph = add_one_directed_edge(graph, 5, 8, 2);
//    graph = add_one_directed_edge(graph, 6, 8, 1);
//    graph = add_one_directed_edge(graph, 7, 8, 3);



    floyd_warshall_algorithm(graph);

    return 0;
}
