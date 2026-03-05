#include <Stdio.h>
#include <stdlib.h> 

int issafe(int row, int col, int board[], int n){
    for(int i = 0; i < row; i++){
        if(board[i] == col || abs(board[i] - col) == abs(row - i) )
            return 0;
    } //board[a] = b: queen in row a, column b
    return 1;
}

void solve(int row, int n, int board[]){
    if(row == n){
        printf("Solution \n");
        for(int i = 0; i < n; i++)
            printf("Row : %d, column : %d \n", i, board[i]);
        printf("\n");
        return;
    }
    for(int col = 0; col < n; col++){
        if(issafe(row, col, board, n)){
            board[row] = col;
            solve(row+1, n, board);
        }
    }
}
int main(){
    int board[5] = {0};
    solve(0, 5, board);
    return 0;
}