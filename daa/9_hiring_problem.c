#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void print(int* arr, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void shuffle(int* arr, int n){
    srand(time(0));
    
    for(int i = 0; i < n; i++){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int cost(int* arr, int n){
    //print(arr, n);
    shuffle(arr, n);
    //print(arr, n);
    int best = arr[0];
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > best)
        {
            best = arr[i];
            count++;
        }
    }
    return count;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d ", cost(arr, 5));
}