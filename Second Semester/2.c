#include<stdio.h>
void main(){
    int n,m,k,game[30]={0},i,times=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;;i++){
        if(game[i%n]==-1) continue;
        times++;
        if(times%m==0){
            printf("%d ",(i%n)+1);
            game[i%n]=-1;
            k--;
        }
        if(k==0){
            if(game[i%n]==0){
                printf("%d\n",(i%n)+1);
                break;
            }
        }
    }
}
