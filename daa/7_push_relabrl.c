#include <stdio.h>
#include <limits.h>
#define V 6

int min(int a, int b) {
    return a < b ? a : b;
}

void push(int u, int v, int capacity[V][V], int flow[V][V], int excess[]){
    int send = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += send;
    flow[v][u] -= send;
    excess[u] -= send;
    excess[v] += send;
}
void relabe(int u, int height[], int capacity[V][V], int flow[V][V]) {
    int min_height = INT_MAX; 
    for (int v = 0; v < V; v++) {
        if (capacity[u][v] - flow[u][v] > 0) {
            min_height = min(min_height, height[v]);
        }
    }
    height[u] = min_height + 1;
}
int push_relabel(int capacity[V][V], int source, int sink) {
    int min_height = INT_MAX; 

    int flow[V][V] = {0};
    int height[V] = {0};
    int excess[V] = {0};
    
    height[source] = V;

    for(int v = 0; v < V; v++) {
        flow[source][v] = capacity[source][v];
        flow[v][source] -= flow[source][v];
        excess[v] = capacity[source][v];
    }
    int active = 1;

    while(active) {
        active = 0;

        for(int u = 0; u < V; u++) {
            if(u != source && u != sink && excess[u] > 0) {
                active = 1;

                int pushed = 0;
                for(int v = 0; v < V && excess[u] > 0; v++) {
                    if(capacity[u][v] - flow[u][v] > 0 &&
                        height[u] == height[v] + 1) {
                        push(u, v, capacity, flow, excess);
                        pushed = 1;
                    }
                }

                if(!pushed) {
                    relabel(u, height, capacity, flow);
                }
            }
        }
    }

    return excess[sink];
}