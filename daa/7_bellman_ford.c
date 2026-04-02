#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w; 

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    int flag = 0;
    for(int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w; 

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            flag = 1;
        }
    }
    if(flag == 1){
        printf("negative cycle");
        return;
    }
    

    // Print result
    for(int i = 0; i < V; i++) {
        printf("Distance from %d to %d is %d\n", src, i, dist[i]);
    }
}

int main() {
    int V = 5;
    int E = 5;

    struct Edge edges[] = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };

    bellmanFord(V, E, edges, 0);
    return 0;
}