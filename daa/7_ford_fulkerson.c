#include <stdio.h>
#include <string.h>
#include <limits.h>

int path_flow = INT_MAX;

#define INF 999999
#define V 4

int dfs(int rGraph[V][V], int s, int t, int parent[]){
    int visited[V] = {0};
    int stack[V], top = -1;

    stack[++top] = s;
    visited[s] = 1;
    parent[s] = -1;

    while(top >= 0){
        int u = stack[top--];

        for(int v = 0; v < V; v++){
            if(!visited[v] && rGraph[u][v] > 0){
                parent[v] = u;
                visited[v] = 1;

                if( v== t)
                    return 1;

                stack[++top] = v;
            }
        }
        return 0;
    }
}
int ford_fulkerson(int graph[V][V], int s, int t){
    int u, v;
    int rGraph[V][V];

    for(u = 0; u < V; u++)
        for(v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while( dfs(rGraph, s, t, parent)){
        int path_flow = 99999;

        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            if(rGraph[u][v] < path_flow) 
                path_flow = rGraph[u][v];
        }

        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow ;
            rGraph[v][u] += path_flow ;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main(){
    int graph[V][V] = {
    {0, 3, 4, 0},
    {0, 0, 2, 3},
    {0, 0, 0, 1},
    {0, 0, 0, 0}
};
    int ans = ford_fulkerson(graph, 0, 3);
    printf("%d ", ans);
    return 0;
}