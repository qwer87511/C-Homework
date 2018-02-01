#include<stdio.h>
int main(){
    char ch=' ';
    int B=0,N=0,a=1;
    double result=0.0;
    scanf("%d %d",&B,&N);
    if(B>=2 && B<=9 && N>0 && N<=100000000){
        while(N>0){
            result+=(N%B)*a;
            N/=B;
            a*=10;
        }
        printf("%.0f",result);
    }
    else{
        printf("-1");
    }
    return 0;
}
