#include<stdio.h>
#include<math.h>
int main(){
    int sign=1,state=0,dot=1;
    double result=0.0;
    char x=' ';
    while(1){
        scanf("%c",&x);
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
            result+=(x-'0')*pow(10,-dot);
            dot++;
        }
        else if(state==2&&x=='\n'){
            printf("error");
            return;
        }
////////////////////////////////////////////////////////
        else if(state==3&&isdigit(x)&&dot<=3){
            result+=(x-'0')*pow(10,-dot);
            dot++;
        }
////////////////////////////////////////////////////////
        else if(state==4&&x=='.'){
            state=2;
        }
        else if(state==4&&x=='\n'&&sign==-1){
                printf("error");
                return;
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
        else if(state==5&&x=='\n'){
                printf("error");
                return;
        }
        else if(x=='\n'){
            break;
        }
        else{
            printf("error\n");
            return;
        }
    }
    result*=sign;
    printf("%.*f\n",dot-1,result);
    main();
}
