#include <stdio.h>
int min(int a, int b){
    if(a < b)
        return a;
    return b;
}
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
int main(){
    int a1[] = {4, 5, 3, 2};
    int a2[] = {2, 10, 1, 4};
    int t1[] = {0, 7, 4, 5};
    int t2[] = {0, 9, 2, 8};
    int e1 = 10, e2 = 12, x1 = 18, x2 = 7;
    printf("ans = %d", assembly(a1, a2, t1, t2, e1, e2, x1, x2, 4));
}