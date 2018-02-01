#include<stdio.h>
#define size 10
int willwin(int box[][size], int a, int b){
    int i,j,sum=0;
    for( i=a-4 , j=b-4 ; i<=a , j<=b ; i++ , j++ ){
        if(i>=0&&i+4<size) if(box[i][b]+box[i+1][b]+box[i+2][b]+box[i+3][b]+box[i+4][b]==4) return 1;
        if(j>=0&&j+4<size) if(box[a][j]+box[a][j+1]+box[a][j+2]+box[a][j+3]+box[a][j+4]==4) return 1;
        if(i>=0&&i+4<size&&j>=0&&j+4<size) if(box[i][j]+box[i+1][j+1]+box[i+2][j+2]+box[i+3][j+3]+box[i+4][j+4]==4) return 1;
        if(i>=0&&i+4<size&&2*b-j-4>=0&&2*b-j<size) if(box[i][2*b-j]+box[i+1][2*b-j-1]+box[i+2][2*b-j-2]+box[i+3][2*b-j-3]+box[i+4][2*b-j-4]==4) return 1;
    }
    return 0;
}
int main(){
    int box[size][size]={0},i,j;
    for( i=0 ; i<size*size ; i++ ) scanf("%d",&box[i/size][i%size]);
    for( i=0 ; i<size ; i++ ) for( j=0 ; j<size ; j++ ) if(!box[i][j]) if(willwin(box,i,j)) printf("%d %d\n",i,j);
}
