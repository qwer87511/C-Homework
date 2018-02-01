#include<stdio.h>
int main(){
    int i,c,s,k=0;
    char a[20];
    for( i=0 ; ; i++ ){
        scanf("%c",&a[i]);
        if(a[i]=='\n') break;
        if(a[i]=='(') { c=i; k++; }
        if(a[i]==')') k--;
    }
    if(k) printf("ERROR INPUT\n");
    else {
        for( i=c+1 ; ; i++ ){
            printf("%c",a[i]);
            if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') s=i;
            if(a[i+1]==')') break;
        }
        printf("\n");
        if(a[s]=='+') printf("%d\n",(a[s-1]-'0')+(a[s+1]-'0'));
        if(a[s]=='-') printf("%d\n",(a[s-1]-'0')-(a[s+1]-'0'));
        if(a[s]=='*') printf("%d\n",(a[s-1]-'0')*(a[s+1]-'0'));
        //if(a[s]=='/') printf("%d\n",(a[s-1]-'0')/(a[s+1]-'0'));
    }
}
