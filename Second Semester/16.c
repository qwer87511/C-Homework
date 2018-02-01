#include<stdio.h>
short go(int maze[40][40], int x, int y,int size){
    if(x==size-2&&y==size-2) return 1;
    if(maze[x][y]!=0) return -1;
    maze[x][y]=2;
    if(go(maze,x+1,y,size)==1) return 1;
    else if(go(maze,x,y+1,size)==1) return 1;
    else if(go(maze,x-1,y,size)==1) return 1;
    else if(go(maze,x,y-1,size)==1) return 1;
    else maze[x][y]=0;
    return -1;
}
void main(){
    int maze[40][40]={0},i,j,size;
    scanf("%d",&size);
    for(i=0;i<size*size;i++)
        scanf(" %d",*(maze+i/size)+i%size);
    go(maze,1,1,size);
    maze[size-2][size-2]=2;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(*(*(maze+i)+j)==2)
                printf("# ");
            else
                printf("%d ",*(*(maze+i)+j));
        }
        printf("\n");
    }
}
