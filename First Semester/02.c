#include<stdio.h>
#include<math.h>
int main(){
    int a=0;
    int b=0;
    int c=0;
    double x1=0.0;
    double x2=0.0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
    x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
    printf("%.1f\n",x1);
    printf("%.1f\n",x2);

}
