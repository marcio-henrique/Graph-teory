#include <stdio.h>
#include "graph.h"
#include "kruskal.h"

Graph *get_graph();

int main() {
    Graph *g = get_graph()

    kruskal_algorithm(g);

    return 0;
}

Graph *get_graph() {

    FILE *in = fopen("../input", "r");

    // verifica se o arquivo existe
    if (!in) {
        printf("Erro! Nao foi possivel abrir o arquivo.\n");
        exit(-1);
    }

    lli n;
    fscanf(in, "%lli", &n);

    Graph *graph = create_graph(n);

    lli v1, v2, w;

    while (fscanf(in, "%lli", &v1) != EOF) {
        fscanf(in, "%lli %lli", &v2, &w);
        graph = add_one_directed_edge(graph, v1, v2, w);
    }

    return graph;
}
