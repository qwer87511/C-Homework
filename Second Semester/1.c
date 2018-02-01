#include<stdio.h>
#define size 4
void num_to_arr(int n, int arr[size]){
    int i;
    for(i=0;i<4;i++){
        arr[i]=n%10;
        n/=10;
    }
}
int confirm(int arr[size]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=i+1;j<4;j++){
            if(arr[i]==arr[j]) return 1;
        }
    }
    return 0;
}
void getAB(int arr1[size], int arr2[size], int *a , int *b){
    int i,j;
    for(i=0;i<4;i++){
        if(arr1[i]==arr2[i]) (*a)++;
        for(j=0;j<4;j++){
            if(arr1[i]==arr2[j]&&i!=j) (*b)++;
        }
    }
}
int comp(int *ans, int in, int a, int b){
    int i,j,k,ta=0,tb=0,arr_ans[size]={0},arr_in[size]={0},temp=*ans;
    num_to_arr(in,arr_in);
    for(;*ans < 10000;(*ans) ++){
        num_to_arr(*ans,arr_ans);
        if(confirm(arr_ans)) continue;
        ta=0,tb=0;
        getAB(arr_ans,arr_in,&ta,&tb);
        //printf("%d %d %dA%dB\n",*ans,in,a,b);
        if(ta==a&&tb==b){
            if(*ans==temp) return 0;
            else return 1;
        }
    }
    return 0;
}
int main(){
    int in[10]={0},a[10]={0},b[10]={0},i=0,j=0,ans=123,temp=0;
    for(i=0;i<10;i++){
        scanf("%d,%dA%dB",&in[i],&a[i],&b[i]);
        for(j=0;j<=i;j++){
            if(comp(&ans,in[j],a[j],b[j])) j=0;
        }
        temp=ans+1;
        for(j=0;j<=i;j++){
            if(comp(&temp,in[j],a[j],b[j])) j=0;
        }
        if(temp==10000) break;
    }
    printf("%d\n",ans);
}
