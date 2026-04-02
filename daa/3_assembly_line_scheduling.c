#include <stdio.h>
int min(int a, int b){
    if(a < b)
        return a;
    return b;
}
//without path
int assembly(int a1[], int a2[], int t1[], int t2[], int e1, int e2, int x1, int x2, int n){
    int l1[n], l2[n];
    l1[0] = e1 + a1[0];
    l2[0] = e2 + a2[0];
    for(int i = 1; i < n; i++){
        l1[i] = min( l1[i-1] + a1[i], l2[i-1] + a2[i] + t2[i-1]);
        l2[i] = min( l2[i-1] + a2[i], l1[i-1] + a1[i] + t1[i-1]);
    }
    int ans = min(l1[n-1] + x1, l2[n-1] + x2);
    return ans;
}
//with path. 
void asp(int n, int t1[100], int t2[100], int e1, int e2, int a1[100], int a2[100], int x1, int x2){
    int l1[100], l2[100], p1[100], p2[100], path[100];
    
    l1[0] = e1 + a1[0];
    l2[0] = e2 + a2[0];
    p1[0] = 1;
    p2[0] = 2;
    
    for(int i = 1; i < n; i++){
        if(l1[i-1] + a1[i] <= l2[i-1] + t2[i-1] + a1[i]){
            l1[i] = l1[i-1] + a1[i];
            p1[i] = 1;
        } else {
            l1[i] = l2[i-1] + t2[i-1] + a1[i];
            p1[i] = 2;
        }
        
        if(l2[i-1] + a2[i] <= l1[i-1] + t1[i-1] + a2[i]){
            l2[i] = l2[i-1] + a2[i];
            p2[i] = 2;
        } else {
            l2[i] = l1[i-1] + t1[i-1] + a2[i];
            p2[i] = 1;
        }
    }
    
    int ans;
    if(l1[n-1] + x1 <= l2[n-1] + x2){
        ans = l1[n-1] + x1;
        path[n-1] = 1;
    } else {
        ans = l2[n-1] + x2;
        path[n-1] = 2;
    }
    
    for(int i = n-1; i > 0; i--){
        if(path[i] == 1)
            path[i-1] = p1[i];
        else
            path[i-1] = p2[i];
    }
    
    printf("Minimum manufacturing time: %d\n", ans);
    printf("Optimal path followed:\n");
    for(int i = 0; i < n; i++)
        printf("Station %d -> Line %d\n", i+1, path[i]);
}

int main(){
    int n, t1[100], t2[100], e1, e2, a1[100], a2[100], x1, x2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a1[i]);
    for(int i = 0; i < n; i++) scanf("%d", &a2[i]);
    scanf("%d %d %d %d", &e1, &e2, &x1, &x2);
    for(int i = 0; i < n; i++) scanf("%d", &t1[i]);
    for(int i = 0; i < n; i++) scanf("%d", &t2[i]);
    asp(n, t1, t2, e1, e2, a1, a2, x1, x2);
}