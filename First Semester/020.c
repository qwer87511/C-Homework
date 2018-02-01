#include<stdio.h>
#include<math.h>
double f1(double a,double x){
    return sqrt(a-pow(x,2));
}
double f2(double a,double x){
    return fabs((a*pow(x,3)+7*x))/sqrt(a+x);
}
int main(){
    int  type=0,again=0,err=0;
    double a=0.0,p=0.0,q=0.0,area=100.0,area_old=0.0,times=2.0,k=0.0,devided=0.0;
    scanf("%d,",&type);
    if(type==0) return 0;
    scanf("%lf,%lf,%lf,%d,",&a,&p,&q,&err);
    for(times=5000.0;fabs(area-area_old)*pow(10,err+1)>=10;times++){
        area_old=area;
        area=0;
        for(k=0;k<times;k++){
            devided=(q-p)/times;
            if(type==1)
                area+=devided*(f1(a,p+k*devided)+f1(a,p+(k+1)*devided))/2;
            else
                area+=devided*(f2(a,p+k*devided)+f2(a,p+(k+1)*devided))/2;
        }
    }
    printf("%.5f",area);
    main();
}
