#include<stdio.h>
#include <stdlib.h>
void print(int* arr, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int* b, int* a){
   int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int* arr, int p, int q){
    int pivot = arr[q];  
    int i = p - 1;
    //printf("%d \n", pivot);
    for(int j = p; j < q; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[q]);
    //print(arr, q-p+1 );
    return i + 1;
}
void randomQuickSort(int* arr, int p, int q){
    if(p >= q)
        return;
    else{
        int r = (rand() % (q - p + 1)) + p;
        swap(&arr[r], &arr[q]);
    
        int j = partition(arr, p, q);
        randomQuickSort(arr, p, j-1);
        randomQuickSort(arr, j+1, q);
    }
    
}
int main(){
    int arr[] = {10, 45, 2, 67, 43, 56, 28, 84, 55};
    randomQuickSort(arr, 0, 8);
    print(arr, 9);
}