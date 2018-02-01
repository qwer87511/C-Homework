#include<stdio.h>
#include<math.h>
int checkinput(double n){
    int in=0,c=0;
    double k=0.0;
    in=(int)n;
    n=n-in;
    for(k=0;k<=0.9;k=k+0.1){
        if(k==n)
            c=1;
        return c;
    }
}
int main(){
    int times=0,w=0;
    double n=0.0,c=0.0;
    scanf("%lf %lf %d",&n,&c,&w);
    if(-100<n && n<0 && c>=0 && c<=10000 && w>=0 && w<=10000 && checkinput(c) /*&& checkinput(c)*/ && getchar()=='\n'){
        while(w>0){
            if(c>=-n){
                c+=n+3;
                times++;
                w--;
            }
            else{
                c+=1.5;
                w--;
            }
        }
        printf("%d\n",times);
    }
    else
        printf("Error\n");
}
