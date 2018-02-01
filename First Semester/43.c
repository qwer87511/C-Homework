#include<stdio.h>
#define size 10
int willwin(int box[size][size], int a, int b){
    int i,j,sum=0;
    for( i=a-4 ; i<=a+4 ; i++ ){
        if (i<0) continue;
        if (i==size) break;
        sum+=box[i][b];
        if (i>a&&i>=5) sum-=box[i-5][b];
        if (sum==4) return 1;
    }
    sum=0;
    for( i=b-4 ; i<=b+4 ; i++ ){
        if (i<0) continue;
        if (i==size) break;
        sum+=box[a][i];
        if (i>a&&i>=5) sum-=box[a][i-5];
        if (sum==4) return 1;
    }
    sum=0;
    for( i=a-4 , j=b-4 ; i<=a+4 , j<=b+4 ; i++ , j++ ){
        if (i<0||j<0) continue;
        if (i==size||j==size) break;
        sum+=box[i][j];
        if (i>a&&i>=5&&j>b&&j>=5) sum-=box[i-5][j-5];
        if (sum==4) return 1;
    }
    sum=0;
    for( i=a-4 , j=b+4 ; i<=a+4 , j>=b-4 ; i++ , j-- ){
        if (i<0||j>=size) continue;
        if (i==size||j<0) break;
        sum+=box[i][j];
        if (i>a&&i>5&&j<b&&j>-5) sum-=box[i-5][j+5];
        if (sum==4) return 1;
    }
    return 0;
}
int main(){
    int box[size][size]={0},i,j;
    for( i=0 ; i<size*size ; i++ ) scanf("%d",&box[i/size][i%size]);
    for( i=0 ; i<size ; i++ ) for( j=0 ; j<size ; j++ ) if(!box[i][j]) {if(willwin(box,i,j)) printf("%d %d\n",i,j);}
    //willwin(box,5,5);
    //for( i=0 ; i<size*size ; i++ ) {printf("%d",box[i/size][i%size]); if(!((i+1)%size)) printf("\n");}
}
