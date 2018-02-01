#include<stdio.h>
int factor(int a,int b){
    if(b==0) return a;
    return factor(b,a%b);
}
void simpilify(int *a,int *b){
    int sim=factor(*a,*b);
    *a/=sim;
    *b/=sim;
}
void minus(int *a_n,int *a_den, int b_n, int b_den){
    *a_n=*a_n*b_den-*a_den*b_n;
    *a_den*=b_den;
    simpilify(a_n,a_den);
}
void erase(int *a_n , int *a_den, int *b_n , int *b_den, int mul_n, int mul_den, int i){
    while(i--)
        minus(a_n+i,a_den+i,b_n[i]*mul_n,b_den[i]*mul_den);
}
void guess(int equ_n[20][21], int equ_den[20][21], int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            erase(equ_n[j],equ_den[j],equ_n[i],equ_den[i],equ_den[i][i]*equ_n[j][i],equ_n[i][i]*equ_den[j][i],n+1);
    for(i=n-1;i>=0;i--)
        for(j=i-1;j>=0;j--)
            erase(equ_n[j],equ_den[j],equ_n[i],equ_den[i],equ_den[i][i]*equ_n[j][i],equ_n[i][i]*equ_den[j][i],n+1);
}
void print(int equ_n[20][21], int equ_den[20][21], int sum){
    int i,n,den;
    for(i=0;i<sum;i++){
        n=equ_n[i][sum]*equ_den[i][i];
        den=equ_den[i][sum]*equ_n[i][i];
        simpilify(&n,&den);
        if(den==1) printf("X[%d] = %d\n",i+1,n);
        else if(n/den>0) printf("X[%d] = %d/%d\n",i+1,abs(n),abs(den));
        else printf("X[%d] = -%d/%d\n",i+1,abs(n),abs(den));
    }
}
int main(){
    int i,j,sum,equ_n[20][21]={0},equ_den[20][21]={0};
    scanf("%d",&sum);
    for(i = 0;i < sum;i ++)
        for(j = 0;j <= sum;j ++){
            scanf(" %d",equ_n[i]+j);
            equ_den[i][j]=1;
        }
    guess(equ_n,equ_den,sum);
    print(equ_n,equ_den,sum);
}
