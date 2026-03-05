#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void bfs(int adj[MAX][MAX], int V, int s){
    int q[MAX], front = 0, rear = 0;
    bool visited[MAX] = {false};

    visited[s] = true;
    q[rear++] = s;

    while(front < rear){
        int curr = q[front++];
        printf("%d ", curr);

        for(int i = 0; i < V; i++){
            if(adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
}
void printAdjacencyMatrix(int adj[MAX][MAX], int V){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void addEdge(int adj[MAX][MAX], int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main(){
    printf("Name : Niveditha A\nREg NO : 24BCE2000\n");

    int V = 5;
    int adj[MAX][MAX] = {0};

    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 0); 

    printf("Adjacency Matrix : \n");
    printAdjacencyMatrix(adj, V);
    printf("BFS starting from 0:\n");
    bfs(adj, V, 0);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dest;
    struct Node* next;
};

struct AdjList{
    struct Node* head;
};

struct Node* createNode(int dest){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> dest = dest;
    newnode -> next = NULL; 
    return newnode;
}

void DFSRec(struct AdjList adj[], int visited[], int s){
    visited[s] = 1;
    printf("%d ", s);

    struct Node* current = adj[s].head;
    while(current != NULL){
        int dest = current -> dest;
        if(!visited[dest]){
            DFSRec(adj, visited, dest);
        }
        current = current -> next;
    }
}
void DFS(struct AdjList adj[], int V, int s){
    int visited[5] = {0};
    DFSRec(adj, visited, s);
}

void addEdge(struct AdjList adj[], int s, int t){
    struct Node* newnode = createNode(t);
    newnode -> next = adj[s].head;
    adj[s].head = newnode;

    newnode = createNode(s);
    newnode -> next = adj[t].head;
    adj[t].head = newnode;
}

int main(){
    int V = 5;
    struct AdjList adj[V];
    for(int i = 0; i < V; i++)
        adj[i].head = NULL;
    
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 0); 

    int source = 0;
    printf("Name : Niveditha A\nREg NO : 24BCE2000\n");
    printf("DFS from source = %d\n", source);
    DFS(adj, V, source); 
}

