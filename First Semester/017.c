#include<stdio.h>
int printdot(int a){
    int k;
    for(k=1;k<=a;k++){
        printf(" ");
    }
}
int printstar(int a){
    int k;
    for(k=1;k<=a;k++){
        printf("*");
    }
}

int main(){
    int a=0,b=0,n=0,k=1,mid=0;
    scanf("%d",&n);
    mid=(n+1)/2;
    for(a=1;a<=n;a++){
        printdot(mid-k);
        printstar(2*k-1);
        printdot(mid-k);
        printf("\n");
        if(a<mid)
            k++;
        else
            k--;
    }
}
