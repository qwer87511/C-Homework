#include<stdio.h>
int judge(int x0, int y0,int x1, int y1,int x2, int y2,int x3, int y3){
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
    return 1;
}
int main(){
    int n,i,j,result=0,x1[20]={0},y1[20]={0},x2[20]={0},y2[20]={0},x3[20]={0},y3[20]={0};
    scanf("%d",&n);
    for( i=0 ; i<n ; i++ ){
        scanf("%d %d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);
    }
    for( i=0 ; i<n ; i++ ){
        for( j=0 ; j<n ; j++ ){
            if(i==j) continue;
            if( judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j])||
                judge(x1[i],y1[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j])||
                judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j])||
                judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j])||
                judge(x3[i],y3[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j])||
                judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j])||
                judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x2[j],y2[j])||
                judge(x1[i],y1[i],x3[i],y3[i],x3[j],y3[j],x2[j],y2[j])||
                judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x3[j],y3[j]) )
            {
                 result++;
                 break;
            }
        }
    }
    printf("%d\n",result);
}
