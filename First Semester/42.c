#include<stdio.h>
#define size 3
int calculate(int box[][size], int a, int b, int ins){
    int i,row=0,column=0,slope=0;
    for(i=0;i<size;i++){
        row+=box[a][i];
        column+=box[i][b];
        if(a==b) slope+=box[i][i];
        else if(a==size-b-1) slope+=box[i][size-i-1];
    }
    if(ins==2&&(row==size||column==size||slope==size)){
        printf("Computer win\n");
        return 1;
    }
    if(ins==2&&(row==-size||column==-size||slope==-size)){
        printf("Player win\n");
        return 1;
    }
    if(ins==1&&(row==size-1||column==size-1||slope==size-1)) printf("Computer will win with (%d, %d)\n",a,b);
    if(ins==0&&(row==1-size||column==1-size||slope==1-size)) printf("Player will win with (%d, %d)\n",a,b);
    return 0;
}
void iswin(int box[][size], char ins){
    int i,j,slope1=0,slope2=0;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            if(!box[i][j]) calculate(box,i,j,1);
        }
    }
    if(ins=='d'){
        for( i=0 ; i<size ; i++ ){
            for( j=0 ; j<size ; j++ ){
                if(!box[i][j]) calculate(box,i,j,0);
            }
        }
    }
}
int main(){
    int box[size][size]={0},i=1,data=0,j;
    char ins=' ';
    scanf("%d",&i);
    if(i==0) i=-1;
    while(1){
        scanf("%c",&ins);
        if(isdigit(ins)){
            scanf("%d",&data);
            if(box[ins-'0'][data]) printf("input error\n");
            else{
                box[ins-'0'][data]=i;
                i*=-1;
            }
        }
        else if(ins=='w'||ins=='d') iswin(box,ins);
        for(j=0;j<size;j++){
            if(calculate(box,j,0,2)) return 0;
        }
    }
}
