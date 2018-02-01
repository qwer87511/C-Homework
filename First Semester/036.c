#include<stdio.h>
void swap(double *a, double *b){
    double temp=*a;
    *a=*b;
    *b=temp;
}
void seq(double a[20], double b[20], int h, int t){
    int i,j;
    for( i=h ; i<t ; i++ ){
        if(a[i+1]==0.123) break;
        for( j=h ; j<t ; j++ ){
            if(a[j+1]==0.123) break;
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                swap(&b[j],&b[j+1]);
            }
        }
    }
}
void print(double d){
    int f[20],n=0,i1=0,i2=1,i;
    while (n<20){
    f[n]=(int)d;
    d-= f[n++];
    if (d < 0.000001) break;
    d = 1.0/d;
    }
    for (i=n-1; i >= 0; --i){
        i1 += i2*f[i];
        if (i) i2 += i1*f[--i];
    }
    if(n&1){
        if(i1%i2) printf("%d/%d",i1,i2);
        else printf("%d",i1/i2);
    }
    else{
        if(i2%i1) printf("%d/%d",i2,i1);
        else printf("%d",i2/i1);
    }
}
int judge(int a_x1, int a_y1, int a_x2, int a_y2,int b_x1, int b_y1, int b_x2, int b_y2, int *point, double *ix ,double *iy){
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
            *(ix+i)=x;
            *(iy+i)=y;
            *(point+i)=x*10000+y*10;
            break;
        }
    }
}
int main(){
    int h,t,n,i,j,x1[20]={0},y1[20]={0},x2[20]={0},y2[20]={0},x3[20]={0},y3[20]={0},point[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    double ix[21],iy[21];
    for(i=0;i<21;i++){
        ix[i]=0.123;
        iy[i]=0.123;
    }
    scanf("%d",&n);
    for( i=0 ; i<n ; i++ ){
        scanf("%d %d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);
    }
    for( i=0 ; i<n-1 ; i++ ){
        for( j=i+1 ; j<n ; j++ ){
            judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j],point,ix,iy);
            judge(x1[i],y1[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j],point,ix,iy);
            judge(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j],point,ix,iy);
            judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j],point,ix,iy);
            judge(x3[i],y3[i],x2[i],y2[i],x3[j],y3[j],x2[j],y2[j],point,ix,iy);
            judge(x3[i],y3[i],x2[i],y2[i],x1[j],y1[j],x3[j],y3[j],point,ix,iy);
            judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x2[j],y2[j],point,ix,iy);
            judge(x1[i],y1[i],x3[i],y3[i],x3[j],y3[j],x2[j],y2[j],point,ix,iy);
            judge(x1[i],y1[i],x3[i],y3[i],x1[j],y1[j],x3[j],y3[j],point,ix,iy);
        }
    }
    seq(ix,iy,0,18);
    for(i=0;i<19;i++){
        if(ix[i]==ix[i+1]){
            h=i;
            for(j=i;j<19;j++){
                if(ix[j]!=ix[j+1]) break;
                t=j;
            }
            seq(iy,ix,h,t+1);
        }
    }
    for( i=0 ; i<20 ; i++ ){
        if(ix[i]==0.123&&iy[i]==0.123) break;
        printf("(");
        if(ix[i]<0) printf("-");
        print(fabs(ix[i]));
        printf(",");
        if(iy[i]<0) printf("-");
        print(fabs(iy[i]));
        printf(")\n");
    }
}
