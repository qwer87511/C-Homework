#include<stdio.h>
int judge(int a_x1, int a_y1, int a_x2, int a_y2,int b_x1, int b_y1, int b_x2, int b_y2){
    double m1,b1,m2,b2,x,y;
    if(a_x1==a_x2){
        if(b_x1<=a_x1&&a_x1<=b_x2||b_x1>=a_x1&&a_x1>=b_x2) return 1;
        else return 0;
    }
    if(b_x1==b_x2){
        if(a_x1<=b_x1&&b_x1<=a_x2||a_x1>=b_x1&&b_x1>=a_x2) return 1;
        else return 0;
    }
    m1=(double)(a_y1-a_y2)/(a_x1-a_x2);
    b1=(double)(a_x2*a_y1-a_x1*a_y2)/(a_x2-a_x1);
    m2=(double)(b_y1-b_y2)/(b_x1-b_x2);
    b2=(double)(b_x2*b_y1-b_x1*b_y2)/(b_x2-b_x1);
    if(m1==m2) return 0;
    x=(b2-b1)/(m1-m2);
    y=m1*(b2-b1)/(m1-m2)+b1;
    if ((a_x1<=x&&x<=a_x2||a_x1>=x&&x>=a_x2)&&(a_y1<=y&&y<=a_y2||a_y1>=y&&y>=a_y2)&&(b_x1<=x&&x<=b_x2||b_x1>=x&&x>=b_x2)&&(b_y1<=y&&y<=b_y2||b_y1>=y&&y>=b_y2)) return 1;
    else return 0;
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
