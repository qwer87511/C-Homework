#include<stdio.h>
int begin(int n){
    int i,result=0;
    for(i = 1 ;i <= n;i ++){
        result*=10;
        result+=i;
    }
    return result;
}
int end(int n){
    int i,result=1;
    for(i = n ;i > 1;i --){
        result*=10;
        result+=i;
    }
    return result;
}
void num_to_arr(int n, int arr[11]){
    int i;
    for(i=0;i<11;i++){
        arr[i]=n%10;
        n/=10;
    }
}
int confirm(int arr[], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]) return 1;
            else if(arr[i]>n) return 1;
            else if(arr[i]==0) return 1;
        }
    }
    return 0;
}
void main(){
    int list[11][11]={0},arr[11]={0},a,b,d,n,m,i,j,distance=0,min=999999;
    scanf("%d,%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d,%d,%d",&a,&b,&d);
        list[a][b]=d;
        list[b][a]=d;
    }
    for(i = begin(n);i <= end(n);i ++){
        num_to_arr(i,arr);
        if(confirm(arr,n)) continue;
        distance=0;
        for(j = 0;j < n-1 ;j ++){
            if(list[arr[j]][arr[j+1]]==0) break;
            distance+=list[arr[j]][arr[j+1]];
        }
        if(j == n-1 && min > distance) min=distance;
    }
    printf("%d\n",min);
}
