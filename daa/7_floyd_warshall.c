#include <stdio.h>
#define INF 9999999
void floyd_warshall(int V, int grpah[V][V]){
    int dist[V][V];

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = grpah[i][j];

    for(int i = 0; i < V; i ++)
        for(int j = 0; j < V; j++)
            for(int k = 0; k < V; k++)
                if(dist[j][i] + dist[i][k] < dist[j][k] )
                    dist[j][k] = dist[j][i] + dist[i][k];

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][j] == INF)
                    printf("INF ");
                else
                    printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
}
int main(){
    int V = 4;
    int graph[4][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    floyd_warshall(V, graph);
    return 0;
}