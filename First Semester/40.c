#include<stdio.h>
void turnright(int box[][10], int size){
    int temp[10][10],i,j;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            temp[j][i]=box[size-i-1][j];
        }
    }
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            box[i][j]=temp[i][j];
        }
    }
}
void turnleft(int box[][10], int size){
    int temp[10][10],i,j;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            temp[j][i]=box[i][size-j-1];
        }
    }
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            box[i][j]=temp[i][j];
        }
    }
}
void turn(int box[][10], int size){
    int temp[10][10],i,j;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            temp[size-i-1][j]=box[i][j];
        }
    }
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            box[i][j]=temp[i][j];
        }
    }
}
int main(){
    int box[10][10]={0},size,i,j;
    char ins=' ';
    scanf("%d",&size);
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            box[i][j]=i*size+j+1;
        }
    }
    while(1){
        scanf("%c",&ins);
        if(ins=='R') turnright(box,size);
        else if(ins=='L') turnleft(box,size);
        else if(ins=='N') turn(box,size);
        else if(ins=='F') break;
    }
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
}
