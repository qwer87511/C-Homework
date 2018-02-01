#include<stdio.h>
#include<math.h>
int fab(int a){
    if(a<0) a=-a;
    return a;
}
int divisible(double d){
    if(floor(d)==d) return 0;
    else if(floor(d*10)==d*10) return 1;
    else return 2;
}
void f1(int x1, int y1, int x2, int y2, double *m, double *b){
    *m=(double)(y1-y2)/(x1-x2);
    *b=(double)(x2*y1-x1*y2)/(x2-x1);
}
void f2(int x1, int y1, int x2, int y2, int *m1, int *m2, int *b1, int *b2){
    *m1=(y1-y2);
    *m2=(x1-x2);
    *b1=(x2*y1-x1*y2);
    *b2=(x2-x1);
}
void simplify(int *a,int *b){
    int d=2;
    while(d<=*a&&d<=*b){
        if(fab(*a)%d==0&&fab(*b)%d==0){
            *a/=d;
            *b/=d;
            d=2;
        }
        else
            d++;
    }
}
int main(){
    int x1=0,x2=0,y1=0,y2=0,m1=0,b1=0,m2=0,b2=0;
    double m=0.0,b=0.0;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    f1(x1,y1,x2,y2,&m,&b);
    f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
    printf("y=");
    if(m==1) printf("x");
    else if(m==-1) printf("-x");
    else if(m) printf("%.*fx",divisible(m),m-0.005);
    if(m&&b>0) printf("+");
    if(b) printf("%.*f",divisible(b),b-0.005);
    printf("\n");
    simplify(&m1,&m2);
    simplify(&b1,&b2);
    double fm1=(double)m1,fm2=(double)m2,fb1=(double)b1,fb2=(double)b2;
    printf("y=");
    if(fm1/fm2==1) printf("x");
    else if(fm1/fm2==-1) printf("-x");
    else if (fm1){
        if(fm1*fm2<0) printf("-");
        if(divisible(fm1/fm2)==0) printf("%.0fx",fabs(fm1/fm2));
        else printf("%.0f/%.0fx",fabs(fm1),fabs(fm2));
    }
    if(fm1&&fb1*fb2>0) printf("+");
    else if(fb1*fb2<0) printf("-");
    if(b1){
        if(divisible(fb1/fb2)==0) printf("%.0f\n",fabs(fb1/fb2));
        else printf("%.0f/%.0f\n",fabs(fb1),fabs(fb2));
    }
}
