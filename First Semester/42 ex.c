#include<stdio.h>
#define size 3
void calculate(int box[][size], int a, int b, int ins ,int num){
    int i,row=0,column=0,slope=0;
    for(i=0;i<size;i++){
        row+=box[a][i];
        column+=box[i][b];
        if(a==b) slope+=box[i][i];
        else if(a==size-b-1) slope+=box[i][size-i-1];
    }
    if(ins&&(row==num||column==num||slope==num)) printf("Computer will win with (%d, %d)\n",a,b);
    if(!ins&&(row==num||column==num||slope==num)) printf("Player will win with (%d, %d)\n",a,b);
}
void willwin(int box[][size], char ins){
    int i,j,slope1=0,slope2=0;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            if(!box[i][j]) calculate(box,i,j,1,size-1);
        }
    }
    if(ins=='d'){
        for( i=0 ; i<size ; i++ ){
            for( j=0 ; j<size ; j++ ){
                if(!box[i][j]) calculate(box,i,j,0,-(size-1));
            }
        }
    }
}
/*int win(int box[][size], int will){
    int i,j,row=0,column=0,slope1=0,slope2=0;
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size ; j++ ){
            row+=box[i][j];
            column+=box[j][i];
        }
        if(row==will||column==will) return 1;
        row=0,column=0;
        slope1+=box[i][i];
        slope2+=box[i][size-i-1];
    }
    if(slope1==will||slope2==will) return 1;
    return 0;
}*/
int main(){
    int box[size][size]={0},i=1,data=0;
    char ins=' ';
    scanf("%d",&i);
    if(i==0) i=-1;
    while(1){
        scanf("%c",&ins);
        if(ins=='w') willwin(box,ins);
        else if(ins=='d') willwin(box,ins);
        else if (isdigit(ins)){
            scanf("%d",&data);
            if(box[ins-'0'][data]) printf("input error\n");
            else{
                box[ins-'0'][data]=i;
                i*=-1;
            }
        }
        willwin(box,0);
    }
}
