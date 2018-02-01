#include<stdio.h>
#include<math.h>
int divisible(double d){
    return (floor(d)==d)?0:2;
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
    while(d<=abs(*a)&&d<=abs(*b)){
        if(abs(*a)%d==0&&abs(*b)%d==0){
            *a/=d;
            *b/=d;
        }
        else d++;
    }
}
int main(){
    int x1=0,x2=0,y1=0,y2=0,m1=0,b1=0,m2=0,b2=0;
    double m=0.0,b=0.0;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if (x1-x2) {
        f1(x1,y1,x2,y2,&m,&b);
        printf("y=");
        if(m==1) printf("x");
        else if(m==-1) printf("-x");
        else if(m) printf("%.*fx",divisible(m),m);
        if(m&&b>0) printf("+");
        if(b) printf("%.*f",divisible(b),b);
        else if(!m&!b) printf("0");
        printf("\n");
        f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
        simplify(&m1,&m2);
        simplify(&b1,&b2);
        printf("y=");
        if(m1==m2) printf("x");
        else if(m1==-m2) printf("-x");
        else if (m1){
            if(m1*m2<0) printf("-");
            if(m1%m2==0) printf("%dx",abs(m1/m2));
            else printf("%d/%dx",abs(m1),abs(m2));
        }
        if(b1){
            if(m1&&b1*b2>0) printf("+");
            else if(b1*b2<0) printf("-");
            if(b1%b2==0) printf("%d",abs(b1/b2));
            else printf("%d/%d",abs(b1),abs(b2));
        }
        else if(!m1&&!b1) printf("0");
    }
    else printf("x=%d\nx=%d\n",x1,x1);
}
