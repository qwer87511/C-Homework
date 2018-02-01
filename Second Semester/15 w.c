#include<stdio.h>
#include<math.h>
int gray(int n, int k){
    if(n==1) {printf("%d",k); return 0;}
    else if(k<pow(2,n-1)) {printf("0"); return gray(n-1,k);}
    else printf("1"); return gray(n-1,pow(2,n)-1-k);
}
void main(){
    int n,k,d;
    scanf("%d %d %d",&n,&k,&d);
    gray(n,k);
    printf("\n");
    if(d==0) main();
}
