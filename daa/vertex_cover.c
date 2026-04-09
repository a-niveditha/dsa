#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];

// Check if a given subset is a vertex cover
bool isVertexCover(int set[], int size, int vertices) {
    for(int i = 1; i <= vertices; i++) {
        for(int j = i+1; j <= vertices; j++) {
            if(graph[i][j]) {
                // edge exists, check if covered
                bool covered = false;
                for(int k = 0; k < size; k++) {
                    if(set[k] == i || set[k] == j) {
                        covered = true;
                        break;
                    }
                }
                if(!covered)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int vertices = 8;

    int edgesData[][2] = {
        {1,6}, {1,2}, {1,4}, {2,3}, {2,4},
        {6,7}, {4,7}, {7,8}, {3,5}, {8,5}
    };

    int edges = sizeof(edgesData)/sizeof(edgesData[0]);

    // Initialize graph
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            graph[i][j] = 0;

    for(int i = 0; i < edges; i++) {
        int u = edgesData[i][0];
        int v = edgesData[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    int bestSet[MAX];
    int minSize = vertices + 1;

    // Try all subsets using bitmask
    int total = 1 << vertices;  // 2^V subsets

    for(int mask = 0; mask < total; mask++) {
        int currentSet[MAX];
        int size = 0;

        for(int i = 0; i < vertices; i++) {
            if(mask & (1 << i)) {
                currentSet[size++] = i + 1;  // vertices are 1-based
            }
        }

        if(size >= minSize) continue;

        if(isVertexCover(currentSet, size, vertices)) {
            minSize = size;
            for(int i = 0; i < size; i++)
                bestSet[i] = currentSet[i];
        }
    }

    printf("Minimum Vertex Cover: ");
    for(int i = 0; i < minSize; i++)
        printf("%d ", bestSet[i]);

    printf("\nSize: %d\n", minSize);

    return 0;
}