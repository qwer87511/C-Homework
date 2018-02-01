#include<stdio.h>
int near(int x0, int y0, int x1, int y1, int chess[3][3]){
    return (x0==x1&&abs(y0-y1)==1||y0==y1&&abs(x0-x1)==1)?1:0;
}
int cannon(int x0, int y0, int x1, int y1, int chess[3][3]){
    if(x0==x1&&abs(y0-y1)==2||y0==y1&&abs(x0-x1)==2)
        if(chess[(x0+x1)/2][(y0+y1)/2]!=-1)
            return 1;
    return 0;
}
int level(int ch){
    ch=ch%100/2;
    return (ch<=5)?6-ch:0;
}
int eat(int a,int b){
    if(a==6&&b==0) return 0;
    else if(a==0&&b==6) return 1;
    else if(a>=b) return 1;
    return 0;
}
void main(){
    int i,j,x,y,data,chess[3][3]={0};
    char name[18][10]={"General","Guard","Elephant","Rook","Horse","Bom","Pawn","Pawn","Pawn","King","Assistant","Bishop","Chariot","Knight","Cannon","Soldier","Soldier","Soldier"};
    for(i = 0;i < 9;i ++){
        scanf("%d %d %d",&x,&y,&data);
        chess[x][y]=data;
    }
    for(i = 0;i < 9;i ++){
        for(j = 0;j < 9;j ++){
            if(chess[i/3][i%3]/100+chess[j/3][j%3]/100==3){
                if(chess[i/3][i%3]%100/2==5){
                    if(cannon(i/3,i%3,j/3,j%3,chess))
                        printf("%s(%d,%d)->%s(%d,%d)\n",name[chess[i/3][i%3]/2-((chess[i/3][i%3]/100==1)?50:91)],i/3,i%3,name[chess[j/3][j%3]/2-((chess[j/3][j%3]/100==1)?50:91)],j/3,j%3);
                }
                else if(near(i/3,i%3,j/3,j%3,chess)){
                    if(eat(level(chess[i/3][i%3]),level(chess[j/3][j%3])))
                        printf("%s(%d,%d)->%s(%d,%d)\n",name[chess[i/3][i%3]/2-((chess[i/3][i%3]/100==1)?50:91)],i/3,i%3,name[chess[j/3][j%3]/2-((chess[j/3][j%3]/100==1)?50:91)],j/3,j%3);
                }
            }
        }
    }
}
