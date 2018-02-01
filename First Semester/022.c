#include<stdio.h>
int checkinput(double n){
    n*=10;
    int in=(int)n,c=0;
    if(n==in) c=1;
    return c;
}
int main(){
    int times=0,w=0;
    double n=0.0,c=0.0;
    char de1=' ',de2=' ',de3=' ';
    scanf("%lf%c%lf%c%d%c",&n,&de1,&c,&de2,&w,&de3);
    if(de1==' ' && de2==' ' && de3=='\n' && -100<n && n<0 && c>=0 && c<=10000 && w>=0 && w<=10000 && checkinput(n) && checkinput(c)){
        while(w>0){
            if(c>=-n){
                c+=n+3;
                times++;
                w--;
            }
            else{
                c+=1.5;
                w--;
            }
        }
        printf("%d\n",times);
    }
    else
        printf("Error\n");
}
