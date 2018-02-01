#include<stdio.h>
void add(int n1, int d1, int n2, int d2, int *a, int *b){
    *a=n1*d2+n2*d1;
    *b=d1*d2;
}
int multiply(int n1, int d1, int n2, int d2, int *a, int *b){
    *a=n1*n2;
    *b=d1*d2;
}
int simplify(int *a, int *b){
    int d=2;
    while(d<=abs(*a)&&d<=abs(*b)){
        if(abs(*a)%d==0&&abs(*b)%d==0){
            *a/=d;
            *b/=d;
        }
        else d++;
    }
}
int printing(int a, int b){
    if(a*b<0) printf("-");
    a=abs(a);
    b=abs(b);
    if(a>=b) {
        printf("%d",a/b);
        if(a%b)
            printf("(%d/%d)",a%b,b);
    }
    else printf("%d/%d",a%b,b);
    printf("\n");
}
int main(){
    int n1=0, d1=0, n2=0, d2=0, a=0, b=0;
    scanf("%d/%d %d/%d", &n1, &d1, &n2, &d2);
    if(n1&&d1&&n2&&d2){
        add(n1, d1, n2, d2, &a, &b);
        simplify(&a, &b);
        printing(a, b);
        multiply(n1, d1, n2, d2, &a, &b);
        simplify(&a, &b);
        printing(a, b);
    }
    else printf( "ERROR\nERROR\n");
}
