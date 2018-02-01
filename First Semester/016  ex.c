#include<stdio.h>
int main(){
    int type=0,n=0,a=0,b=0,k=1;
    scanf("%d %d",&type,&n);
    if(type==1){
        for(a=1;a<=n;a++){
            for(b=1;b<=k;b++){
                printf("%d",b);
            }
            if (a<=(n-1)/2)
                k++;
            else
                k--;
            printf("\n");
        }
    }
    else{
        for(a=1;a<=n;a++){
            for(b=1;b<=(n+1)/2-k;b++){
                printf(".");
            }
            for(b=k;b>=1;b--){
                printf("%d",b);
            }
            if (a<=(n-1)/2)
                k++;
            else
                k--;
            printf("\n");
        }
    }
}
