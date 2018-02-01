#include<stdio.h>
int main(){
    double k,c=0.2,n=0.3;
    c+=0.1;
    if (c==n)
        printf("yes");
    else
        printf("%.999f",c);
}
