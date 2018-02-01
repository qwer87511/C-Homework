
#include<stdio.h>
int cover(int x11,int x12,int x21,int x22){
    int c=0;
    if(x11<=x21 && x21<=x12 && x12<=x22)
        c=x12-x21;
    else if(x11<=x21 && x21<=x12 && x22<=x12)
        c=x22-x21;
    return c;
}
int main(){
    int x1=0,x2=0,x1_old=0,x2_old=0,i=0,a=0,m=0;
    scanf("%d",&i);
    for(a=1;a<=i;a++){
        scanf("%d %d",&x1,&x2);
        m=m+(x2-x1);
        m=m-cover(x1_old,x2_old,x1,x2);
        x1_old=x1;
        x2_old=x2;
    }
    printf("%d\n",m);
}
