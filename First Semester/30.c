#include<stdio.h>
void print(int *num){
    int i;
    for( i=119 ; i>=1 ; i-- ){
        if(*(num+i)) break;
    }
    for(  ; i>=0 ; i-- ){
        printf("%d",*(num+i));
    }
    printf("\n");
}
void input(int *num){
    char in=' ';
    int i=0;
    while(1){
        scanf("%c",&in);
        if(in=='\n') break;
        for( i=60 ; i>0 ; i-- ){
            *(num+i)=*(num+i-1);
        }
        *num=in-'0';
    }
}
void add(int *num1, int *num2){
    int i=0,j=0,result[120]={0};
    for( i=0 ; i<60 ; i++ ){
        result[i+1]+=(*(num1+i)+*(num2+i)+result[i])/10;
        result[i]=(*(num1+i)+*(num2+i)+result[i])%10;
    }
    print(result);
}
void sub(int *num1, int *num2){
    int i=0,j=0,result[120]={0};
    for( i=0 ; i<60 ; i++ ){
        if (*(num1+i)+result[i]<*(num2+i)) {
            result[i+1]--;
            result[i]+=10;
        }
        result[i]+=*(num1+i)-*(num2+i);
    }
    print(result);
}
void mul(int *num1, int *num2){
    int i=0,j=0,result[120]={0};
    for( i=0 ; i<60 ; i++ ){
        for ( j=0 ; j<60 ; j++ ){
            result[i+j+1]+=(*(num1+i)**(num2+j)+result[i+j])/10;
            result[i+j]=(*(num1+i)**(num2+j)+result[i+j])%10;
        }
    }
    print(result);
}
int main(){
    int num1[120]={0},num2[120]={0};
    input(num1);
    input(num2);
    add(num1,num2);
    sub(num1,num2);
    mul(num1,num2);
}
