//
// Created by ikkeg on 12/01/2021.
//
#include "union-find.h"

void make_set(lli *father, lli *rank, lli size)
{
    for(lli i = 0; i < size; i++) {
        father[i] = i;
        rank[i] = 0;
    }
}
lli find(lli *father, lli i) {
    if (father[i] != i) {
        father[i] = find(father, father[i]);
    }
    return father[i];
}
void make_union(lli *father, lli *rank, lli x, lli y) {
    if (rank[x] >= rank[y]) {
        father[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    } else {
        father[x] = y;
    }
}