#include<stdio.h>
#include<math.h>
double rule(int sign,int state,double dot,double k){
    int ik=(int)k;
    if(sign==1 && state==1 && 2<=k && k<= 1000) k=k;
    else if(k==0||k==1) k=1000;
    else if(sign==-1 && state==1 && -1000<=k && k<=-1) k*=-11;
    else if(sign==1 && state==3 && 2<=k && k<= 1000) k=floor(k);
    else if(sign==-1 && state==3 && -1000<=k && k<=-1) k=(ik-k)/dot/10;
    else return 0;
    return k;
}
int main(){
    int i=0,j=0,sign=1,state=0;
    double result=0.0,k=0.0,dot=0.1;
    char x=' ';
    while(1){
        scanf("%c",&x);
        if(x=='\n') {
            if(state==2||state==5||state==4&&sign==-1){
                printf("error");
                return;
            }
            else
                break;
        }
////////////////////////////////////////////////////////
        if(state==0&&isdigit(x)&&x!='0'){
            state=1;
            result+=x-'0';
        }
        else if(state==0&&x=='0'){
            state=4;
        }
        else if(state==0&&x=='-'){
            sign=-1;
            state=5;
        }
////////////////////////////////////////////////////////
        else if(state==1&&isdigit(x)){
            result*=10;
            result+=x-'0';
        }
        else if(state==1&&x=='.'){
            state=2;
        }
////////////////////////////////////////////////////////
        else if(state==2&&isdigit(x)){
            state=3;
            result+=(x-'0')*dot;
            dot/=10;
        }
////////////////////////////////////////////////////////
        else if(state==3&&isdigit(x)&&dot>=0.001){
            result+=(x-'0')*dot;
            dot/=10;
        }
////////////////////////////////////////////////////////
        else if(state==4&&x=='.'){
            state=2;
        }
////////////////////////////////////////////////////////
        else if(state==5&&isdigit(x)&&x!='0'){
            state=1;
            result*=10;
            result+=x-'0';
        }
        else if(state==5&&x=='0'){
            state=4;
        }
        else{
            printf("error");
            return;
        }
        printf("%f\n",result);
    }
    result*=sign;
    k=rule(sign,state,dot,result);
    if(k){
        for(i=k+0.00001;i>=2;i--){
            for(j=2;j<i;j++){
                if(i%j==0) break;
            }
            if(j==i) break;
        }
        printf("%d\n",j);
    }
    else
        printf("error\n");
}
