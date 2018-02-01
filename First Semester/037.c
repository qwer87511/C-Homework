#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0};
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=0 ; i<len-1 ; i++){
        for( j=0 ; j<len-1-i ; j++ ){
            if(arr[j]<arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
                (*times)++;
            }
        }
    }
    for( i=0 ; i<len ; i++ ) {
        printf("%d ",arr[i]);
    }
}
void bubble_sort2(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0};
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=0 ; i<len-1 ; i++){
        for( j=0 ; j<len-1-i ; j++ ){
            if(arr[j]>arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
                (*times)++;
            }
        }
    }
    for( i=0 ; i<len ; i++ ) {
        printf("%d ",arr[i]);
    }
}
void insertion_sort(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0},temp=arr[0];;
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=1 ; i<len ; i++){
        temp=arr[i];
        for( j=i-1 ; j>=0 && arr[j]<temp ; j-- ){
            arr[j+1]=arr[j];
            (*times)++;
        }
        if(arr[j+1]<temp){
           arr[j+1]=temp;
        }
    }
}
void insertion_sort2(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0},temp=arr[0];;
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=1 ; i<len ; i++){
        temp=arr[i];
        for( j=i-1 ; j>=0 && arr[j]>temp ; j-- ){
            arr[j+1]=arr[j];
            (*times)++;
        }
        if(arr[j+1]>temp){
           arr[j+1]=temp;
        }
    }
}
void selection_sort(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0},ex=0;
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=0 ; i<len-1 ; i++){
        ex=i;
        for( j=i+1 ; j<len ; j++ ){
            if(arr[ex]<arr[j]) ex=j;
        }
        if(ex!=i){
            swap(&arr[i],&arr[ex]);
            (*times)++;
        }
    }
}
void selection_sort2(int *data, int len, int *times){
    int i=0,j=0,arr[25]={0},ex=0;
    for(i=0;i<len;i++) arr[i]=data[i];
    for( i=0 ; i<len-1 ; i++){
        ex=i;
        for( j=i+1 ; j<len ; j++ ){
            if(arr[ex]>arr[j]) ex=j;
        }
        if(ex!=i){
            swap(&arr[i],&arr[ex]);
            (*times)++;
        }
    }
}
int main(){
    int i=1,times1=0,times2=0,times3=0,data[25]={0},type=2;
    scanf("%d",&data[0]);
    while(data[i-1]!=-999)
        {scanf("%d",&data[i++]);}
    scanf("%d",&type);
    if(type==1){
        bubble_sort(data,i-1,&times1);
        insertion_sort(data,i-1,&times2);
        selection_sort(data,i-1,&times3);
    }
    else if(type==0){
        bubble_sort2(data,i-1,&times1);
        insertion_sort2(data,i-1,&times2);
        selection_sort2(data,i-1,&times3);
    }
    printf("\n");
    printf("Bubble Sort change times = %d\n",times1);
    printf("Insertion Sort change times = %d\n",times2);
    printf("Selection Sort change times = %d\n",times3);
}
