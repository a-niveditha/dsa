
#include <stdio.h> 
#include <stdlib.h> 
void printArray(int A[], int l1, int r1) 
{ 
    int i; 
    for (i = l1; i <= r1; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
 
void merge(int arr[], int l, int m, int r) 
{ 
    printArray(arr, l, r); 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    printf("After sorting = ");
    printArray(arr, l, r); 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
int main() 
{ 
    printf("Name:Niveditha \nReg No:24BCE2000 \n");
    int arr[] = { 12, 70, 11, 100, 90, 2, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    printf("Given array is \n"); 
    printArray(arr, 0, arr_size-1); 
    mergeSort(arr, 0, arr_size - 1); 
    printf("\nSorted array is \n"); 
    printArray(arr, 0, arr_size-1); 
    return 0; 
}
    

#include <stdio.h> 
 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void printArray(int arr[], int start, int stop)  
{ 
    for (int i = start; i <= stop; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int partition(int arr[], int low, int high) { 
    printArray(arr, low, high); 
    int pivot = arr[low]; 
    int start = low; 
    int end = high; 
    int k = high;  
    for (int i = high; i > low; i--) { 
        if (arr[i] >= pivot) 
            swap(&arr[i], &arr[k--]); 
    } 
    swap(&arr[low], &arr[k]); 
    return k; 
}
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int idx = partition(arr, low, high); 
        quickSort(arr, low, idx - 1); 
        quickSort(arr, idx + 1, high); 
    } 
} 
 
int main() { 
    printf("Name:Niveditha \nReg No:24BCE2000 \n");
    int arr[] = {4, 3, 6, 9, 2, 4, 3, 1, 2, 1, 8, 9, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1); 
    printf("Sorted array: \n"); 
    printArray(arr, 0, n-1); 
    return 0; 
} 
    

#include <stdio.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
   
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
 
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    printf("Name:Niveditha \nReg No:24BCE2000 \n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    countingSort(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
} 