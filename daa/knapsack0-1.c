#include <stdio.h>
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
int knapsack(int n, int w[], int val[], int W){
    int V[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else{
                int pick = 0;
                if(w[i-1] <= j)
                    pick = val[i-1] + V[i-1][j - w[i-1]];
                int notpick = V[i-1][j];
                V[i][j] = max(pick, notpick);
            }
        }
    }
    return V[n][W];
}
int main(){
    int values[] = {20, 5, 10, 40, 15, 25};
    int weights[] = {1, 2, 3, 8, 7, 4};
    int capacity = 10;
    printf("%d ", knapsack(6, weights, values, capacity));
}
