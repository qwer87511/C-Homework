#include<stdio.h>
int judge(int x0, int y0,int x1, int y1,int x2, int y2,int x3, int y3,int *result){
    int a0=y0-y1;
    int b0=x1-x0;
    int c0=x1*y0-x0*y1;
    int a1=y2-y3;
    int b1=x3-x2;
    int c1=x3*y2-x2*y3;
    int d=a0*b1-b0*a1;
    int dx=c0*b1-b0*c1;
    int dy=a0*c1-c0*a1;
    if(d==0) return 0;
    double x=(double)dx/d;
    double y=(double)dy/d;
    if (!(((x0>=x&&x>=x1)||(x0<=x&&x<=x1))&&((y0>=y&&y>=y1)||(y0<=y&&y<=y1))&&((x2>=x&&x>=x3)||(x2<=x&&x<=x3))&&((y2>=y&&y>=y3)||(y2<=y&&y<=y3)))) return 0;
    int i;
    for( i=0 ; i<20 ; i++ ) {
        if(*(result+i)==x*12+y*34) return;
    }
    for( i=0 ; i<20 ; i++ ) {
        if(*(result+i)==999) {
            *(result+i)=x*12+y*34;
            break;
        }
    }
}
int main(){
    int x0[10]={0},x1[10]={0},x2[10]={0},y0[10]={0},y1[10]={0},y2[10]={0},amount,i,j,result[20]={0};
    for( i=0 ; i<20 ; i++ ) result[i]=999;
    scanf("%d",&amount);
    for( i=0 ; i<amount ; i++) scanf("%d %d %d %d %d %d",&x0[i],&y0[i],&x1[i],&y1[i],&x2[i],&y2[i]);
    for( i=0 ; i<amount-1 ; i++ ){
        for( j=i+1 ; j<amount ; j++ ){
            judge(x0[i],y0[i],x1[i],y1[i],x0[j],y0[j],x1[j],y1[j],result);
            judge(x0[i],y0[i],x1[i],y1[i],x1[j],y1[j],x2[j],y2[j],result);
            judge(x0[i],y0[i],x1[i],y1[i],x2[j],y2[j],x0[j],y0[j],result);
            judge(x1[i],y1[i],x2[i],y2[i],x0[j],y0[j],x1[j],y1[j],result);
            judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j],result);
            judge(x1[i],y1[i],x2[i],y2[i],x2[j],y2[j],x0[j],y0[j],result);
            judge(x2[i],y2[i],x0[i],y0[i],x0[j],y0[j],x1[j],y1[j],result);
            judge(x2[i],y2[i],x0[i],y0[i],x1[j],y1[j],x2[j],y2[j],result);
            judge(x2[i],y2[i],x0[i],y0[i],x2[j],y2[j],x0[j],y0[j],result);
        }
    }
    for( i=0 ; i<20 ; i++ ) {
        if(*(result+i)==999) break;
    }
    printf("%d",i);
}
