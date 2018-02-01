#include<stdio.h>
void main(){
    unsigned long long int n,i,stair[70]={1,1,2};
    scanf("%d",&n);
    for(i=3;i<=n;i++) stair[i]=stair[i-1]+stair[i-2]+stair[i-3];
    printf("%lld",stair[n]);
}
