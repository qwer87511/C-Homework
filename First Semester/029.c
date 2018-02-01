#include<stdio.h>
int input(int *eq){
    int i=0,j=0,coe=0,power=0,sign=1,state=0;
    char data=' ';
    while(data!='\n'){
        scanf("%c",&data);
        if(data=='+') sign=1;
        if(data=='-') sign=-1;
        if(state==0 && isdigit(data)){
            coe+=(data-'0');
            state=1;
        }
        else if(state==0 && data=='x'){
            coe=1;
            state=2;
        }
        else if(state==1 && isdigit(data)){
            coe=coe*10+(data-'0');
        }
        else if(state==1 && data=='x'){
            state=2;
        }
        else if(state==2 && data=='^'){
            state=3;
        }
        else if(state==2 && (data==' '||data=='\n')){
            power=1;
        }
        else if(state==3 && isdigit(data)){
            power=power*10+(data-'0');
        }
        if(data==' '||data=='\n'){
            *(eq+power)+=coe*sign;
            coe=0,power=0,state=0;
        }
    }
}
int add(int *eq1 ,int *eq2, int *result){
    int i;
    for( i=0 ; i<20 ; i++ ){
        *(result+i)=*(eq1+i)+*(eq2+i);
    }
}
int sub(int *eq1 ,int *eq2, int *result){
    int i;
    for( i=0 ; i<20 ; i++ ){
        *(result+i)=*(eq1+i)-*(eq2+i);
    }
}
int mul(int *eq1 ,int *eq2, int *result){
    int i=0,j=0;
    for( i=0 ; i<20 ; i++){
        for( j=0 ; j<=i ; j++){
            *(result+i)+=*(eq1+j)**(eq2+i-j);
        }
    }
}
int output(int *eq){
    int i=0,c=0;
    for(i=19;i>=1;i--){
        if(*(eq+i)){
            if(*(eq+i)==1) printf("x");
            else if(*(eq+i)==-1) printf("-x");
            else printf("%dx",*(eq+i));
            *(eq+i)=0;
            c=1;
            if(i>1) printf("^%d",i);
            break;
        }
    }
    for(i=19;i>=1;i--){
        if(*(eq+i)){
            if(*(eq+i)==1) printf(" + x");
            else if(*(eq+i)==-1) printf(" - x");
            else if(*(eq+i)>0) printf(" + %dx",*(eq+i));
            else if(*(eq+i)<0) printf(" - %dx",-*(eq+i));
            if(i>1) printf("^%d",i);
        }
    }
    if(c&&*eq>0) printf(" + %d",*eq);
    else if(c&&*eq<0) printf(" - %d",-*eq);
    else if(*eq) printf("%d",*eq);
}
int main(){
    int eq1[20]={0},eq2[20]={0},result[20]={0},c=0,i=0;
    char cal=' ';
    scanf("%c%c",&cal);
    input(eq1);
    input(eq2);
    if(cal=='+') add(eq1,eq2,result);
    else if(cal=='-') sub(eq1,eq2,result);
    else if(cal=='*') mul(eq1,eq2,result);
    output(result);
}
