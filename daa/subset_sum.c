#include <stdio.h>
void subset(int sum, int k, int remaining, int target, int n, int x[], int w[]){
    if(sum == target){
        printf("Subset : ");
        for(int i = 0; i < k; i++)
            if(x[i] == 1)
                printf("%d ", w[i]);
        return;
    }
    if(k == n || sum > target || sum + remaining < target){
        return;
    }
    x[k] = 1;
    subset(sum + w[k], k+1, remaining - w[k], target, n, x, w);

    x[k] = 0;
    subset(sum, k+1, remaining - w[k], target, n, x, w);
}
int main(){
    int elements[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int x[10];
    subset(0, 0, 87, 35, 7, x, elements);
}