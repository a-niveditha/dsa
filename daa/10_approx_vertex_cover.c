#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];
bool included[MAX];

void vertexCover(int vertices, int edges){
    bool edgesRemaining[MAX][MAX];
    for(int i = 0; i < vertices; i++)
        for(int j = 0; j < vertices; j++)
            edgesRemaining[i][j] = graph[i][j];
    
    bool hasEdges = true;
    while (true)
    {
        int u = -1, v = -1;
        for( int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++)
                if(edgesRemaining[i][j]){
                    u = i;
                    v = j;
                    break;
                }
            if(u != -1) 
                break;
        }
        
        if(u == -1) break;

        included[u] = true;
        included[v] = true;
        for(int i = 0; i < vertices; i++){
            edgesRemaining[u][i] = false;
            edgesRemaining[i][u] = false;
        
            edgesRemaining[v][i] = false;
            edgesRemaining[i][v] = false;
        }
    }
}
int main() {
    int vertices = 8, edges = 10;
    int edgesData[][2] = {{1,6}, {1,2}, {1,4}, {2,3}, {2,4}, {6,7}, {4,7}, {7,8}, {3,5}, {8,5}};
    for (int i = 0; i < edges; i++) {
        int u = edgesData[i][0];
        int v = edgesData[i][1];
        graph[u][v] = graph[v][u] = 1;
    }
    vertexCover(vertices, edges);
    printf("Vertex Cover: ");
    for (int i = 1; i <= vertices; i++) {
        if (included[i]) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
