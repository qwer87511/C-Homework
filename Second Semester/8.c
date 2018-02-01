#include<stdio.h>
int read(char ch[300], int *p){
    int i,result=0,b=*p;
    for(;isdigit(ch[*p]);(*p)++);
    for(i = (*p)-1;i >= b;i --){
        result*=10;
        result+=ch[i]-'0';
    }
    return result;
}
void decrypt1(){
    char ch[300]=" ";
    int p,ans=0;
    scanf("%[^\n] ",ch);
    for(p = 0;ch[p] != '\0';p++){
        if(isdigit(ch[p])) ans+=read(ch,&p);
    }
    printf("%04d",ans%10000);
}
int pos(char data[127][2], char in){
    int i;
    for(i = 0;data[i][0] != '\0';i ++){
        if(data[i][0]==in) break;
    }
    data[i][0]=in;
    return i;
}
void pop(char data[127][2], int max[4], int n){
    int i=3,min=3;
    while(i--){
        if(data[max[min]][1]>data[max[i]][1]) min=i;
    }
    for(;min<3;min++){
        max[min]=max[min+1];
    }
    max[3]=n;
}
void findmax(char data[127][2], int max[4]){
    int i,j;
    for(i = 0; i < 127;i ++){
        for(j = 0;j < 4;j ++){
            if(data[i][1]>data[max[j]][1]&&data[i][1]<10){
                pop(data,max,i);
                break;
            }
        }
    }
}
void decrypt2(){
    char ch[300]="\0",data[127][2]={'\0'};
    int i,j,max[4]={126,126,126,126};
    scanf("%[^\n]",ch);
    for(i = 0;ch[i] != '\0';i ++){
        data[pos(data,ch[i])][1]++;
    }
    findmax(data,max);
    for(i = 0;i < 4;i ++) printf("%d",data[max[i]][1]);
}
void main(){
    decrypt1();
    decrypt2();
}
