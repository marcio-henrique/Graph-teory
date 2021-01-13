//
// Created by ikkeg on 12/01/2021.
//

#ifndef GRAPH_TEORY_UNION_FIND_H
#define GRAPH_TEORY_UNION_FIND_H

typedef long long int lli;

void make_set(lli *father, lli *rank, lli size);
lli find(lli *father, lli i);
void make_union(lli *father, lli *rank, lli x, lli y);
#endif //GRAPH_TEORY_UNION_FIND_H
