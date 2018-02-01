#include<stdio.h>
int judge(int a_x1, int a_y1, int a_x2, int a_y2,int b_x1, int b_y1, int b_x2, int b_y2, int *point){
    int i;
    double m1,b1,m2,b2,x=999,y=999;
    if (a_x1==a_x2&&b_x1!=b_x2){
        m2=(double)(b_y1-b_y2)/(b_x1-b_x2);
        b2=(double)(b_x2*b_y1-b_x1*b_y2)/(b_x2-b_x1);
        x=a_x1;
        y=m2*x+b2;
    }
    else if (b_x1==b_x2&&a_x1!=a_x2){
        m1=(double)(a_y1-a_y2)/(a_x1-a_x2);
        b1=(double)(a_x2*a_y1-a_x1*a_y2)/(a_x2-a_x1);
        x=b_x1;
        y=m1*x+b1;
    }
    else {
        m1=(double)(a_y1-a_y2)/(a_x1-a_x2);
        b1=(double)(a_x2*a_y1-a_x1*a_y2)/(a_x2-a_x1);
        m2=(double)(b_y1-b_y2)/(b_x1-b_x2);
        b2=(double)(b_x2*b_y1-b_x1*b_y2)/(b_x2-b_x1);
        if(m1==m2) {
            if(a_x1==b_x1&&a_y1==b_y1||a_x1==b_x2&&a_y1==b_y2){
                x=a_x1;
                y=a_y1;
            }
            else if(a_x2==b_x1&&a_y2==b_y1||a_x2==b_x2&&a_y2==b_y2){
                x=a_x2;
                y=a_y2;
            }
            else return 0;
        }
        else {
            x=(b2-b1)/(m1-m2);
            y=m1*(b2-b1)/(m1-m2)+b1;
        }
    }
    if(!((a_x1<=x&&x<=a_x2||a_x1>=x&&x>=a_x2)&&(a_y1<=y&&y<=a_y2||a_y1>=y&&y>=a_y2)&&(b_x1<=x&&x<=b_x2||b_x1>=x&&x>=b_x2)&&(b_y1<=y&&y<=b_y2||b_y1>=y&&y>=b_y2))) return 0;
    for( i=0 ; i<20 ; i++ ){
        if(*(point+i)==x*10000+y*10) return 0;
    }
    for( i=0 ; i<20 ; i++ ){
        if(*(point+i)==1) {
            *(point+i)=x*10000+y*10;
            break;
        }
    }
}
int main(){
    int n,i,j,x1[20]={0},y1[20]={0},x2[20]={0},y2[20]={0},x3[20]={0},y3[20]={0},point[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    scanf("%d",&n);
    for( i=0 ; i<n ; i++ ){
        scanf("%d %d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);
    }
    for( i=0 ; i<n ; i++ ){
        for( j=i+1 ; j<n ; j++ ){
            judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j],point);
            judge(x1[i],y1[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j],point);
            judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j],point);
            judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j],point);
            judge(x3[i],y3[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j],point);
            judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j],point);
            judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x2[j],y2[j],point);
            judge(x1[i],y1[i],x3[i],y3[i],x3[j],y3[j],x2[j],y2[j],point);
            judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x3[j],y3[j],point);
        }
    }
    for( i=0 ; i<20 ; i++ ){
        if(point[i]==1) break;
    }
    printf("%d",i);
}
