/*
#include <stdio.h>
void print(int arr[], int n){
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}

void insertion(int arr[], int n)
{
for(int j = 1; j < n; j++)
{
int key = arr[j];
int i = j - 1;
while(i >= 0 && key < arr[i])
{
arr[i+1] = arr[i];
printf("j = %d, i = %d, array in inner loop= ", j, i);
print(arr, n);
i --;
}
arr[i+1] = key;
printf("array after every outer loop = ");
print(arr, n);
}
printf("final sorted array = ");
print(arr, n);
}

int main(){
int a[] = {12, 34, 32, 13, 876, 987, 533, 324, 78, 19, 87, 102};
insertion(a, 12);
return 0;
} 
*/

/*
#include <stdio.h>
void print(int arr[], int n){
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}

void swap(int* a, int* b){
int temp = *a; 
*a = *b;
*b = temp;
}

void bubble(int arr[], int n){
for(int i = 0; i < n - 1; i++) {
for(int j = 0; j < n-i-1; j++)
if(arr[j] > arr[j+1])
{
swap(&arr[j], &arr[j+1]);
printf("i = %d j = %d, array in inner loop after every swap= ", i, j);
print(arr, n);
}
} 
printf("final array after sorting = ");
print(arr, n); 
}

int main(){
int a[] = {12, 34, 32, 13, 876, 987, 533, 324, 78, 19, 87, 102};
bubble(a, 12);
return 0;
}
*/

/*
#include <stdio.h>
void print(int arr[], int n){
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}

void swap(int* a, int* b){
int temp = *a; 
*a = *b;
*b = temp;
}

void selection(int arr[], int n){
for(int i = 0; i < n; i++)
{
int min = i;
for(int j = i + 1; j < n; j++)
if(arr[j] < arr[min])
{
min = j;
printf("i = %d j = %d min = %d \n", i, j, min);
} 
swap(&arr[min], &arr[i]);
printf("array after every outer loop = ");
print(arr, n);
}
printf("final array after sorting = ");
print(arr, n);
}
int main(){
int a[] = {12, 34, 32, 13, 876, 987, 533, 324, 78, 19, 87, 102};
selection(a, 12);
return 0;
}
*/
/* 
#include <stdio.h>
int main(){
    int n;
    printf("enter no of elements in the array\n");
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int c = 0;
    int val;
    printf("enter value to be searched\n");
    scanf("%d", &val);
    for(int i = 0; i < n; i++)
        if(a[i] == val)
        {
            c++;
            printf("value found at index = %d", i);
        }
    if(c == 0)
        printf("value not found");
}
*/
/*
#include <stdio.h>
int binarySearch(int a[], int l, int u, int val){
    // u - upper index, l - lower index, val - value to be searched
    int mid = (u + l) / 2;
    if(val == a[mid])
        return mid;
    else if(u < l)
        return -1;
    else if (val > a[mid] )
        binarySearch(a, mid + 1, u, val);
    else if(val < a[mid])
        binarySearch(a, l, mid - 1, val);
}
int main() {
    int n;
    printf("enter no of elements in the array\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int val;
    printf("enter value to be searched\n");
    scanf("%d", &val);
    int ans = binarySearch(a, n-1, 0, val);
    if(ans == -1)
        printf("element not found");
    else
        printf("element found at index = %d", ans);
}
*/

