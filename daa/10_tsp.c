#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];   // cost matrix
int parent[MAX];       // MST parent
bool visited[MAX];
int V;

// ----------- FIND MIN KEY (for Prim) -----------
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// ----------- PRIM'S MST -----------
void primMST(int root) {
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[root] = 0;
    parent[root] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}

// ----------- BUILD MST ADJ LIST -----------
int mstAdj[MAX][MAX];  // adjacency matrix for MST

void buildMST() {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            mstAdj[i][j] = 0;

    for (int i = 1; i < V; i++) {
        int u = parent[i];
        int v = i;
        mstAdj[u][v] = mstAdj[v][u] = 1;
    }
}

// ----------- PREORDER DFS -----------
void preorderDFS(int u) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < V; v++) {
        if (mstAdj[u][v] && !visited[v]) {
            preorderDFS(v);
        }
    }
}

// ----------- APPROX TSP -----------
void approxTSP(int root) {
    primMST(root);
    buildMST();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    printf("Approx TSP Tour: ");
    preorderDFS(root);
    printf("%d\n", root);  // return to start
}

// ----------- MAIN -----------
int main() {
    V = 5;

    int input[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Copy graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = input[i][j];

    approxTSP(0);  // start from vertex 0

    return 0;
}