#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int u;
    int v;
} Edge;

typedef struct{
    int *parent;
    int *rank;
}DSU;
//dsu - disjoint set union
DSU* createDSU(int n){
    DSU* d = (DSU*)malloc(sizeof(DSU));
    d->parent = (int*)malloc(n * sizeof(int));
    d->rank = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        d->parent[i] = i;
        d->rank[i] = 0;
    }
    return d;
}
//path compression - finds root recursively and makes all nodes in the path point to the root
int find(DSU* d, int i){
    if(d->parent[i] != i)
        d->parent[i] = find(d, d->parent[i]);
    return d->parent[i];
}

void unionSet(DSU* d, int x, int y){
    int rootX = find(d, x);
    int rootY = find(d, y);
    if(rootX != rootY){
        if(d->rank[rootX] > d->rank[rootY])
            d->parent[rootY] = rootX;
        else if(d->rank[rootX] < d->rank[rootY])
            d->parent[rootX] = rootY;
        else{
            d->parent[rootY] = rootX;
            d->rank[rootX]++;
        }
    }
}
int kargerMinCut(int n, Edge* edge, int e){
    int vertices = n;
    DSU* d = createDSU(n);

    while(vertices > 2){
        int i = rand() % e;
        int set1 = find(d, edge[i].u);
        int set2 = find(d, edge[i].v);
        if(set1 != set2){
            unionSet(d, set1, set2);
            vertices--;
        }
    }
    int minCut = 0;
    for(int i = 0; i < e; i++){
        if(find(d, edge[i].u) != find(d, edge[i].v)) 
        //are u and v in diff components            
            minCut++;
    }

    free(d->parent);
    free(d->rank);
    free(d);
    return minCut;
}

int main(){
    srand(time(NULL));

    int n = 4;

    // Graph:
    // 0—1
    // |  |
    // 2—3
    Edge edges[] = {
        {0,1}, {1,3}, {3,2}, {2,0}, {0,3}
    };

    int e = sizeof(edges)/sizeof(edges[0]);

    int minCut = 100000;

    // Run multiple times (VERY IMPORTANT)
    for(int i = 0; i < 100; i++){
        int cut = kargerMinCut(n, edges, e);
        if(cut < minCut)
            minCut = cut;
    }

    printf("Minimum Cut = %d\n", minCut);

    return 0;
}