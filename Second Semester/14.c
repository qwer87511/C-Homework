#include<stdio.h>
int circuit(int data){
    if(data==0||data==1) return 0;
    if(data%2) return circuit((data+1)/2)+1;
    else return circuit(data/2)+1;
}
int re(int data){
    if(data==0) return 0;
    return circuit(data)+re(data-1);
}
void main(){
    int data=0,i,times;
    char in=' ';
    while(1){
        data=0,in=' ';
        while(1){
            scanf("%c",&in);
            if(in=='\n') break;
            data=data*2+(in-'0');
        }
        times=re(data);
        for(i=1024;i;i/=2) printf(i&times?"1":"0");
        printf("\n");
        scanf("%d%c",&data);
        if(data==-1) break;
    }
}
