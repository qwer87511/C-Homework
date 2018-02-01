#include<stdio.h>
int add(int *arr, int *a, int data){
    int i=0;
    for( i=0 ; i<*a ; i++ ){
        if(arr[i]==data) break;
    }
    if(i==*a){
        arr[i]=data;
        (*a)++;
    }
}
int del(int *arr, int *a, int data){
    int i=0,j=0;
    for(i=0;i<*a;i++){
        if(*(arr+i)==data){
            for(j=i;j<*a;j++){
                *(arr+j)=*(arr+j+1);
            }
            (*a)--;
        }
    }
}
int printall(int *arrA, int a, int *arrB, int b){
    int i=0;
    printf("A:[");
    for( i=0 ; i<a ; i++ ){
        printf("%d,",*(arrA+i));
    }
    printf("]B:[");
    for( i=0 ; i<b ; i++ ){
        printf("%d,",*(arrB+i));
    }
    printf("]\n");
}
int main(){
    int ins=0;
    int data=0;
    int arrA[20]={0};
    int arrB[20]={0};
    int a=0,b=0,i=0,j=0,p=0,q=0,c=0;
    while(1){
        scanf("%d", &ins);
        if (ins==0) break;
        if ( ins>=3 && ins<=6 ) scanf("%d", &data);
////////////////////////////////////////////////////////////////////////////////
        if(ins==1){
            a=0;
            printall(arrA,a,arrB,b);
        }
        if(ins==2){
            b=0;
            printall(arrA,a,arrB,b);
        }
        if(ins==3){
            add(arrA,&a,data);
            printall(arrA,a,arrB,b);
        }
        if(ins==4){
            add(arrB,&b,data);
            printall(arrA,a,arrB,b);
        }
        if(ins==5){
            del(arrA,&a,data);
            printall(arrA,a,arrB,b);
        }
        if(ins==6){
            del(arrB,&b,data);
            printall(arrA,a,arrB,b);
        }
        if(ins==7){
            printf("[");
            for( p=0 ; p<a ; p++){
                printf("%d,",arrA[p]);
            }
            for( p=0 ; p<b ; p++){
                for( q=0 ; q<a ; q++){
                    if(arrB[p]==arrA[q]) break;
                }
                if(q==a) printf("%d,",arrB[p]);
            }
            printf("]\n");
        }
        if(ins==8){
            printf("[");
            for( p=0 ; p<a ; p++){
                for( q=0 ; q<b ; q++){
                    if(arrA[p]==arrB[q]) printf("%d,",arrA[p]);
                }
            }
            printf("]\n");
        }
        if(ins==9){
            c=0;
            for( p=0 ; p<a ; p++){
                for( q=0 ; q<b ; q++){
                    if(arrA[p]==arrB[q]) c++;
                }
            }
            if(c==a) printf("1\n");
            else printf("0\n");
        }
    }
}
