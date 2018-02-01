#include<stdio.h>
void judge(int data[], int *r){
    int i=0,num[26]={0},pair=0,three=0,c=0;
    for( i=0 ; i<5 ; i++ ){
        num[(data[i]/10)-1]+=1;
        num[(data[i]/10)+12]+=1;
    }
    for( i=0 ; i<13 ; i++ ){
        if (num[i]==2) pair++;
        if (num[i]==3) three++;
        if (num[i]==4) *r=5;
    }
    if( pair==1 && three==1 ) *r=4;
    else if (pair==1) *r=1;
    else if (pair==2) *r=2;
    else if (three) *r=3;
    for( i=2 ; i<=14 ; i++ ){
        if(num[i-2]==1&&num[i-1]==1&&num[i]==1&&num[i+1]==1&&num[i+2]==1){
            if (data[0]%10==data[1]%10 && data[1]%10==data[2]%10 && data[2]%10==data[3]%10 && data[3]%10==data[4]%10) *r=7;
            else *r=6;
        }
    }
}
int main(){
    int data[5]={0};
    int i=0,r=0;
    for( i=0 ; i<5 ; i++ ){
        scanf("%d",&data[i]);
    }
    judge(data,&r);
    printf("%d\n",r);
}
