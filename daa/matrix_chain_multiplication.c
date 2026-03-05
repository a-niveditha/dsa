#include <stdio.h>
int matrix_chain(int p[], int n, int ll, int ul){
    int m[n][n];
    int s[n][n];
    for(int i = 1; i < n; i++)
        m[i][i] = 0;
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 99999;
            for(int k = i; k <= j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[j]*p[k];
                if( q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[ll][ul];
}
int main(){
    int p[] = { 23, 26, 27, 20 };
    int n = sizeof(p) / sizeof(p[0]);
    printf("Minimum number of multiplications is %d ", matrix_chain(p, n, 1, n-1));
}