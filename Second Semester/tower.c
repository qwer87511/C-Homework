#include<stdio.h>
void move(char sou,char des,char tmp,int n,int m){
    if(m==n)
        printf("%c:%c%d\n",des,sou,n);
    else{
        move(sou,des,tmp,n,m-1);
        printf("%d:%c:%c\n",m,sou,des);
        move(des,tmp,sou,n,m-1);
    }
}
int main(){
    move('A','B','C',1,3);
}
