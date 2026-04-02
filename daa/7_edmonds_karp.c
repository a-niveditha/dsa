#include <stdio.h>
#include <string.h>

#define V 6

int bfs(int rGraph[V][V], int s, int t, int parent[]) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while(front < rear) {
        int u = queue[front++];
        //using queue will make sure we get lowest no of edges
        for(int v = 0; v < V; v++) {
            if(!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return visited[t];
}
int edmondsKarp(int graph[V][V], int s, int t){
    int rGraph[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];
    
    int parent[V];
    int max_flow = 0;

    while(bfs(rGraph, s, t, parent)){
        int path_flow = 99999;

        for(int v = t; v != s; v = parent[v]){
            //t → parent[t] → parent[parent[t]] → ... → s
            int u = parent[v];
            if(rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}