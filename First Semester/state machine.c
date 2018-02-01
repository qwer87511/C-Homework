#include<stdio.h>
int main(){
    int sign=1,state=0,idot=0;
    double result=0.0,dot=0.1;
    char x=' ';
    while(1){
        scanf("%c",&x);
        if(x=='\n') {
            if(state==2||state==5||state==4&&sign==-1){ //
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
    }

    result*=sign;
    idot=1/dot+1;
    printf("%d\n",idot);
    printf("%.*f\n",idot%10,result);
}
