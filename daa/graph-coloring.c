#include <Stdio.h>
#include <stdlib.h> 

int issafe(int v, int col, int n, int graph[][10], int color[]){
    for(int i = 0; i < n; i++){
        if(graph[v][i] && color[i] == col )
            return 0;
    } 
    return 1;
}

void solve(int v,int col, int n, int graph[][10], int color[]){
    if(v == n){
        printf("Solution \n");
        for(int i = 0; i < n; i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }
    for(int c = 1; c <= col; c++){
        if(issafe(v, c, n, graph, color)){
            color[v] = c;
            solve(v+1, col, n, graph, color);
            color[v] = 0;
        }
    }
}
int main(){
    int graph[5][10] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,0},
    {0,1,1,0,1},
    {0,0,0,1,0}
    };
    int color[5] = {0};
    solve(0, 3, 5, graph, color); // 3 - no of colours(parameter col)
    return 0;
}