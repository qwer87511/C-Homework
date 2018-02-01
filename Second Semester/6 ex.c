#include<stdio.h>
void givelevel(int data[20][2], int level[20], int n, int top){
    int i,j;
    for(i = 0;i < n-1;i ++){
        if(data[i][0]==top){
            level[data[i][1]]=level[top]+1;
            givelevel(data,level,n,data[i][1]);
        }
    }
}
int up(int s, int data[20][2], int n, int *d){
    int i,p;
    (*d)++;
    for(i = 0;i < n-1;i ++){
        if(data[i][1]==s) return data[i][0];
    }
}
int distance(int a, int b, int data[20][2], int level[20], int n){
    int i,j,d=0;
    while(a!=b){
        if(level[a]==level[b]){
            a=up(a,data,n,&d);
            b=up(b,data,n,&d);
        }
        else if(level[a]>level[b]) a=up(a,data,n,&d);
        else b=up(b,data,n,&d);
    }
    return d;
}
int main(){
    int data[20][2]={0},level[20]={0},i,j,n,top;
    scanf("%d",&n);
    top=(n-1)*n/2;
    for(i = 0;i < n-1;i ++){
        scanf("%d %d",&data[i][0],&data[i][1]);
        top-=data[i][1];
    }
    givelevel(data,level,n,top);
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) printf("%d-%d-%d\n",i,j,distance(i,j,data,level,n));
}
