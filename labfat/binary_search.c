#include <stdio.h>
int binary(int arr[], int u, int l, int val){ //u - upper, l - lower
    int m = (u + l ) / 2;
    if(arr[m] == val)
        return m;
    else if(u < l)
        return -1;
    else if(arr[m] < val)
        binary(arr, u, m+1, val);
    else if(arr[m] > val)
        binary(arr, m-1, l, val);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d %d", binary(arr, 4, 0, 1), binary(arr, 4, 0, 6));
    return 0; 
}
