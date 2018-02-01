#include<stdio.h>
#include<string.h>
/*void selection_sort(int arr[], int len) {
	int i, j, min, temp;
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
	   	temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}*/
void swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}
void swapchar(char arr1[10],char arr2[10]){
    char temp[10]="\0";
	strcpy(temp,arr1);
	strcpy(arr1,arr2);
	strcpy(arr2,temp);
}
void arr_selection_sort(char arr[30][10],int n) {
	int i, j, min;
	for (i = 0; i < n-1; i++) {
		min = i;
		for (j = i + 1; j < n; j++){
			if (strcmp(arr[min],arr[j])>0) min = j;
		}
        swapchar(arr[min],arr[i]);
	}
}
void selection_sort(int arr[], int len) {
	int i, j, min, temp;
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
	   	swap(arr[min],arr[i]);
	}
}

void main(){
    int i,p,n;
    char arr2[30][10]={"sss\0","aaa\0","ASA\0","sas\0","asa\0"};
    int arr1[5]={3,2,1,5,4};
    selection_sort(arr1,5);
    for(i=0;i<5;i++) printf("%s %d\n",arr2[i],arr1[i]);
}
