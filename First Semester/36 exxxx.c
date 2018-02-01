#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swapd(double *a, double *b){
    double temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int *data1, int *data2 , int *data3){
    int i=0,j=0,ex;
    double arr[20]={0};
    for( i=0 ; i<19 ; i++ ) arr[i]=(double)data1[i]/data3[i];
    for( i=0 ; i<19 ; i++ ){
        ex=i;
        for( j=i+1 ; j<20 ; j++ ){
            if(arr[ex]>arr[j]) ex=j;
        }
        if(arr[ex]<arr[i]){
            swapd(&arr[i],&arr[ex]);
            swap(&data1[i],&data1[ex]);
            swap(&data2[i],&data2[ex]);
            swap(&data3[i],&data3[ex]);
        }
    }
}
void print(int a, int b){
    int d=2;
    if(a>0&&b<0||a<0&&b>0) printf("-");
    a=abs(a);
    b=abs(b);
    if(a%b){
        while(d<=a&&d<=b){
            if(a%d==0&&b%d==0){
                a/=d;
                b/=d;
            }
            else d++;
        }
        printf("%d/%d",a,b);
    }
    else printf("%d",a/b);
}
void judge(int x0, int y0,int x1, int y1,int x2, int y2,int x3, int y3, int *id, int *idx, int *idy){
    int a0=y0-y1;
    int b0=x1-x0;
    int c0=x1*y0-x0*y1;
    int a1=y2-y3;
    int b1=x3-x2;
    int c1=x3*y2-x2*y3;
    int d=a0*b1-b0*a1;
    int dx=c0*b1-b0*c1;
    int dy=a0*c1-c0*a1;
    if(d==0) return;
    double x=(double)dx/d;
    double y=(double)dy/d;
    if (!(((x0>=x&&x>=x1)||(x0<=x&&x<=x1))&&((y0>=y&&y>=y1)||(y0<=y&&y<=y1))&&((x2>=x&&x>=x3)||(x2<=x&&x<=x3))&&((y2>=y&&y>=y3)||(y2<=y&&y<=y3)))) return;
    int i;
    for( i=0 ; i<20 ; i++ ){
        if((double)idx[i]/id[i]==x&&(double)idy[i]/id[i]==y) return;
    }
    for( i=0 ; i<20 ; i++ ){
        if(idx[i]==0) {
            id[i]=d;
            idx[i]=dx;
            idy[i]=dy;
            break;
        }
    }
}
void main(){
    int tri[10][3][2]={0},i,j,k,amount,id[20]={0},idx[20]={0},idy[20]={0};
    scanf("%d",&amount);
    for( i=0 ; i<amount ; i++) for( j=0 ; j<3 ; j++) for( k=0 ; k<2 ; k++) scanf("%d",&tri[i][j][k]);
    for( i=0 ; i<amount-1 ; i++ ){
        for( j=i+1 ; j<amount ; j++ ){
            for( k=0 ; k<9 ; k++){
                judge(tri[i][k/3][0],tri[i][k/3][1],tri[i][((1+k/3))%3][0],tri[i][((1+k/3))%3][1],tri[j][k%3][0],tri[j][k%3][1],tri[j][(k+1)%3][0],tri[j][(k+1)%3][1],id,idx,idy);
            }
        }
    }
    selection_sort(idy,idx,id);
    selection_sort(idx,idy,id);
    for( i=0 ; i<20 ; i++ ) {
        if(id[i]!=0){
            printf("(");
            print(idx[i],id[i]);
            printf(",");
            print(idy[i],id[i]);
            printf(")\n");
        }
    }
}
