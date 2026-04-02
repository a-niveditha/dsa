#include <stdio.h>

void print(int s[][100], int i, int j){
    if(i == j){
        printf("A%d", i);
        return;
    }
    printf("(");
    print(s, i, s[i][j]);
    print(s, s[i][j] + 1, j);
    printf(")");
}

void matrix(int p[], int n, int ll, int ul){
    int m[100][100];
    int s[100][100];
    
    for(int i = 0; i < n; i++)
        m[i][i] = 0;
    
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 99999;
            for(int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimum number of multiplications: %d\n", m[ll][ul]);
    printf("Optimal parenthesization: ");
    print(s, ll, ul);
}

int main(){
    int n, p[100];
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    matrix(p, n, 1, n);
}