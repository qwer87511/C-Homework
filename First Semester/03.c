#include<stdio.h>
#include<math.h>
int main(){
    int a=0;
    int b=0;
    double Sum=0.0;
    double Difference=0.0;
    double Product=0.0;
    double Quotient=0.0;
    scanf("%d",&a);
    scanf("%d",&b);
    Sum=a+b;
    Difference=a-b;
    Product=a*b;
    Quotient=(double)a/b;
    printf("Sum:%.2f\n",Sum);
    printf("Difference:%.2f\n",Difference);
    printf("Product:%.2f\n",Product);
    printf("Quptient:%.2f\n",Quotient);
}
