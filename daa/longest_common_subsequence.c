#include <stdio.h>
void print(char b[][100], int x[], int i, int j){
    if(i == 0 || j == 0)
        return;
    else if(b[i][j] == 'd'){
        print(b, x, i-1, j-1);
        printf("%d ", x[i-1]); 
    }
    else if(b[i][j] == 'u')
        print(b, x, i-1, j);
    else
        print(b, x, i, j-1);
}
void LCS(int x[], int y[], int m, int n){
    int c[m+1][n+1];
    char b[m+1][100];
    for(int i = 0; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n ; j++){
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd'; // arrow towards north west - diagonal
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';  // arrow towards north - up
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 's';  // arrow towards west - side
            }
        }
    }
    print(b, x, m, n);
}
int main(){
    int x[] = {1, 2, 3, 4};       
    int y[] = {1, 3, 2, 4, 5};

    LCS(x, y, 4, 5);
    return 0;
}