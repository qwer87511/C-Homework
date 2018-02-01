#include<stdio.h>
int checkinput(double n){
    int in=0;
    n*=100;
    in=(int)n;
    if(in%10==0)
        return 1;
    else
        return 0;
}
int main(){
    int times=0,w=0,w_dot=12345;
    double n=0.0,c=0.0;
    scanf("%lf %lf %d",&n,&c,&w);
    if(checkinput(n)&&checkinput(c)&&getchar()=='\n'){
        while(c+w*1.5>=-n){
            if(c>=-n){
                c=c+n+3;
                times++;
                w--;
            }
            else{
                while(c<-n){
                    c+=1.5;
                    w--;
                }
            }
        }
        printf("%d\n",times);
    }
    else{
        printf("Error");
        while(getchar()!='\n'){}
    }
    main();
}
