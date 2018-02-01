#include<stdio.h>
int main(){
    int x1=0,x2=0,x1_old=0,x1_old_old=0,x2_old=0,i=0,a=0,score=0;
    for(a=1;a<=10;a++){
        scanf("%d %d",&x1,&x2);
        if (x1_old==10){
            if(x1_old_old==10)
                score=score+(x1*3)+(x2*2);
            else
                score=score+(x1*2)+(x2*2);
        }
        else if ((x1_old+x2_old)==10)
            score=score+(x1*2)+x2;
        else
            score=score+x1+x2;
        x1_old_old=x1_old;
        x1_old=x1;
        x2_old=x2;
    }
    scanf("%d",&x1);
    printf("%d\n",score+x1);
}
