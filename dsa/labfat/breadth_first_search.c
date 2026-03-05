#include <stdio.h>
#include <stdbool.h>
void addEdge(int adj[100][100], int a, int b){
    adj[a][b] = 1;
    adj[b][a] = 1;
}
void bfs(int adj[100][100], int V, int s){
    bool visited[V+1];  
    for(int i = 0; i <= V; i++) {
        visited[i] = false;  
    }
    int q[V+1];
    int rear = 0, front = 0;
    visited[s] = true;
    q[rear++] = s;
    while(front < rear){
        int curr = q[front++];
        printf("%d ", curr);
        for(int i = 1; i <= V; i++){
            if(adj[curr][i] == 1 && !visited[i] ){
                visited[i] = true;
                q[rear++] = i
            }
        }
    }
}
int main(){
    int adj[100][100] = {0};
    addEdge(adj, 2, 1);
    addEdge(adj, 5, 1);
    addEdge(adj, 2, 4 );
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    bfs(adj, 7, 1);
}
