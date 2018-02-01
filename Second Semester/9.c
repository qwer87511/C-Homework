#include<stdio.h>
#include<string.h>
void getwords(char sen[100], char *words[30]){
    int i;
    words[0]=strtok(sen," ");
    for(i = 1;i < 30;i ++){
        words[i]=strtok(NULL," ");
    }
}
void getcount(char p[30][10], int n, char *words[30], int count[30]){
    int i,j;
    for(i = 0;i < n;i ++){
        for(j = 0;words[j] != NULL;j ++){
            if(strcmp(p[i],words[j])==0) count[i]++;
        }
    }
}
void popwords(char *words[30], char p[30][10], int n){
    int i,j,sum=0;
    for(i = 0;words[i] != NULL;i ++){
        for(j = 0;j < n;j ++){
            if(strcmp(words[i],p[j])==0) break;
        }
        if(j==n){
            printf("%s ",words[i]);
            sum++;
        }
    }
    printf("\n%d\n",sum);
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swapchar(char arr1[10],char arr2[10]){
    char temp[10]="\0";
	strcpy(temp,arr1);
	strcpy(arr1,arr2);
	strcpy(arr2,temp);
}
void selection_sort(int arr1[30], char arr2[30][10], int n) {
	int i, j, max;
	for (i = 0; i < n - 1; i++) {
		max = i;
		for (j = i + 1; j < n; j++)
			if (arr1[max] < arr1[j]||arr1[max]==arr1[j]&&strcmp(arr2[max],arr2[j])>0)
				max = j;
	   	swap(&arr1[max],&arr1[i]);
	   	swapchar(arr2[max],arr2[i]);
	}
}
void* main(){
    char p[30][10]={'\0'},sen[100]="\0",*words[30];
    int i=0,n,count[30]={0};
    for(n=0;;n++){
        scanf("%s ",p[n]);
        if(p[n][0]=='-') break;
    }
    scanf("%[^\n]",sen);
    getwords(sen,words);
    getcount(p,n,words,count);
    popwords(words,p,n);
    selection_sort(count,p,n);
    for(i=0;i<30;i++) if(count[i]) printf("%s %d\n",p[i],count[i]);
}
