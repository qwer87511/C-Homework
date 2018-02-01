#include<stdio.h>
int main(){
    while(1){
        int k=0,result=1,last=1,last_last=1,c=0,z=1;
        double n=0.0;
        char er=' ';
        scanf("%lf%c",&n,&er);
        while(er!='\n'){
            scanf("%c",&er);
            z=0;
        }
        if(n==-1) return;
        if(z){
            for(k=1;k<=n-2;k++){
                result=last+last_last;
                last_last=last;
                last=result;
            }
            printf("%d\n",result);
        }
        else{
            printf("Error\n");
        }
    }
}
