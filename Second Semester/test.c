#include<stdio.h>
#include<stdlib.h>
int *f(){
    int *a=(int*)malloc(sizeof(int));
    *a=5;
}
int main(){
    printf("%d",*f());
}
