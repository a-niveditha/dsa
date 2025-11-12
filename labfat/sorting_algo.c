
#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubble(int arr[], int n){ 
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]){ //just push the bigger element to the end
                swap(&arr[j], &arr[j+1]);
                print(arr, n);
            }
}
void insertion(int arr[], int n){
    for(int j = 0; j < n-1; j++){
        int key = arr[j];
        int i = j-1; //pick j, and ur going to insert tje jth element before.
        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            print(arr, n);
            i--;
        }
        arr[i + 1] = key; 
    }
}
void selection(int arr[], int n){
    int i, j, min; //find the min element and swap it after each inner loop. 
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;
        if(min != i){
            swap(&arr[i] , &arr[min]);
            print(arr, n);
        }
    }
}
int main(){
    int n = 5;
    int arr[] = {34, 56, 2, 5, 71};
    print(arr, n);
    //bubble(arr, n);
    insertion(arr, n);
    //selection(arr, n);
    print(arr, n);
    return 0;
}



