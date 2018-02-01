#include<stdio.h>
#define SIZE 512
void push(char *stack, char in, int *top){
    stack[++(*top)]=in;
}
void pop(char *stack, int *top){
    printf("%c",stack[(*top)--]);
}
int priority(char op){
    switch(op){
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
int main(){
    int top=-1;
    char in=' ',stack[SIZE]={'\0'};
    while(1){
        scanf("%c",&in);
        if(in=='\n') break;
        else if(in=='(') push(stack,in,&top);
        else if(in=='+'||in=='-'||in=='*'||in=='/'||in=='^') {
            while(top>=0&&(priority(stack[top])>=priority(in))) pop(stack,&top);
            push(stack,in,&top);
        }
        else if(in==')') {
            while(stack[top]!='(') pop(stack,&top);
            top--;
        }
        else printf("%c",in);
    }
    while(top>=0) printf("%c",stack[top--]);
}
