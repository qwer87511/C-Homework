#include<stdio.h>
void main(){
    int good[50][21]={0},n,i,j,k,in,max=0,temp=0,mi=0,mj=0;
    char ch=' ';
    scanf("%d",&n);
    for(i = 0;i < n;i ++){
        ch=' ';
        while(1){
            scanf("%d%c",&in,&ch);
            good[i][in]++;
            if(ch!=',') break;
        }
    }
    for(i = 1;i < 20;i ++){
        for(j = i+1;j < 21;j ++){
            temp=0;
            for(k = 0;k < n;k ++)
                if(good[k][i]&&good[k][j])
                    temp++;
            if(temp>max){
                max=temp;
                mi=i;
                mj=j;
            }
        }
    }
    printf("%d,%d,%d\n",mi,mj,max);
}
