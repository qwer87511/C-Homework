#include<stdio.h>
void walk(int start, int n, unsigned long long int *times){
    if(start==n) {(*times)++;return;}
    if(start<=n-3) walk(start+3, n, times);
    if(start<=n-2) walk(start+2, n, times);
    walk(start+1, n, times);
}
void main(){
    int n;
    unsigned long long int times=0;
    scanf("%d",&n);
    walk( 0, n, &times);
    printf("%lld",times);
}
