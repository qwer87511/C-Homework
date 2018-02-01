#include<stdio.h>
int sol(int sudoku[][9], int x, int y){
    int i,j;
    sudoku[x][y]++;
    for( i=0 ; i<9 ; i++ ){
        for( j=0 ; j<9 ; j++ ){
            if( x!=j && sudoku[x][y]==sudoku[j][y] || y!=j && sudoku[x][y]==sudoku[x][j] ) sudoku[x][y]++;
            if(i/3==x/3&&j/3==y/3&&x!=i&&y!=j){
                if(sudoku[x][y]==sudoku[i][j]) sudoku[x][y]++;
            }
        }
    }
    return sudoku[x][y];
}
int main(){
    int sudoku[9][9]={0},i,j;
    char data=' ';
    for( i=0 ; i<9 ; i++ ){
        for( j=0 ; j<9 ; j++ ){
            scanf(" %c",&data);
            sudoku[i][j]=data-'0';
        }
    }
    for( i=0 ; i<9 ; i++ ){
        for( j=0 ; j<9 ; j++ ) if(sudoku[i][j]==0) printf("%d %d %d\n",i,j,sol(sudoku,i,j));
        printf("\n");
    }
}
