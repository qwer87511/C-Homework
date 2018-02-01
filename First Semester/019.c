#include<stdio.h>
#include<math.h>
int main(){
    double type=0.0,n=0,c=0.0,d=0.0,f1=0.0,df1=0.0,f2=0.0,df2=0.0,x=0.0;
    int err=0;
    scanf("%lf %lf %lf %lf %d",&type,&n,&c,&d,&err);
    x=d/2;
    if(type==1){
        do{
            f1=pow(x,n)-c*pow(x,n-2)-d;
            df1=n*pow(x,n-1)-(n-2)*c*pow(x,n-3);
            x=x-f1/df1;
        }while(fabs(f1/df1*pow(10,err))>=1);
    }
    else{
        do{
            f2=pow(x,n)-c*x-d;
            df2=n*pow(x,n-1)-c;
            x=x-(f2/df2);
        }while(fabs(f2/df2*pow(10,err))>=1);
    }
    x=x-5*pow(10,-(err+2));
    printf("%.*f\n",err+1,x);
}

