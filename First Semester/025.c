#include<stdio.h>
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area){
    if(*perimeter<abs(x1-x2)*2+abs(y1-y2)*2)
        *perimeter=abs(x1-x2)*2+abs(y1-y2)*2;
    if(*area<abs(x1-x2)*abs(y1-y2))
        *area=abs(x1-x2)*abs(y1-y2);
}
int main(){
    int x1=0,y1=0,x2=0,y2=0,perimeter=0,area=0;
    while(1){
        scanf("%d",&x1);
        if(x1==-1) break;
        scanf("%d %d %d",&y1,&x2,&y2);
        compute(x1,y1,x2,y2,&perimeter,&area);
    }
    printf("%d\n%d\n",area,perimeter);
}
