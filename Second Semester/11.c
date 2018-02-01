#include<stdio.h>

int main(){
    char p[10]="\0",ins=' ',art[300]="\0",*words[30];
    int n,sumw=0,found[10]={0},sumf=0;
    scanf("%s %d %c %[^\n]",p,&n,&ins,art);
    strlwr(art);
    cut(art,words,&sumw);
    find(p,words,sumw,found,&sumf);
    selection_sort(found,sumf,words,sumw,(ins=='R')?1:-1);
    print(p,words,sumw,found,sumf,n);
}
