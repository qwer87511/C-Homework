#include<stdio.h>
int main(){
    int x1=0,x2=0,x3=0,x1_old=0,x1_old_old=0,x2_old=0,i=0,a=0,m=0,sum=0;
    for(a=1;a<=9;a++){
        scanf("%d %d",&x1,&x2);
        if (x1_old==10 && x1_old_old==10){
            x1=x1*3;
            x2=x2*2;
        }
        else if (x1_old==10){
            x1=x1*2;
            x2=x2*2;
        }
        else if (x1_old+x2_old==10)
            x1=x1*2;
        m=m+x1+x2;
        x1_old_old=x1_old;
        x1_old=x1;
        x2_old=x2;
    }
    scanf("%d %d %d",&x1,&x2,&x3);
    if(x1_old==10){
        m=m+(x1*2)+(x2*2)+x3;
    }
    else if(x1_old+x2_old==10){
        m=m+(x1*2)+x2+x3;
    }
    else
        m=m+x1+x2+x3;
    printf("%d",m);
}
