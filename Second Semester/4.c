#include<stdio.h>
int win(int box[3][3]){
    int i,j,row=0,column=0,slope1=0,slope2=0;
    for(i=0;i<3;i++){
        row=0,column=0;
        for(j=0;j<3;j++){
            row+=box[i][j];
            column+=box[j][i];
        }
        slope1+=box[i][i];
        slope2+=box[i][2-i];
        if(row==3||column==3) return 1;
    }
    if(slope1==3||slope2==3) return 1;
    return 0;
}
void writearr(int arr[10]){
    int i,in;
    for(i = 0;i < 9;i ++){
        scanf("%d",&in);
        arr[in]=i;
    }
}
void main(){
    int rule1[10]={0},rule2[10]={0},box1[3][3]={0},box2[3][3]={0},i,in;
    writearr(rule1);
    writearr(rule2);
    for(i=0;i<3;i++){
        scanf("%d",&in);
        box1[rule1[in]/3][rule1[in]%3]=1;
        box2[rule2[in]/3][rule2[in]%3]=1;
    }
    if(win(box1)&&win(box2)) printf("Draw\n");
    else if(win(box1)) printf("Player1 wins\n");
    else if(win(box2)) printf("Player2 wins\n");
    else printf("Draw\n");
    scanf("%d",&in);
    if(in==0) main();
}
