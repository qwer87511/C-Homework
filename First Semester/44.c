#include<stdio.h>
#define size 3
int count(int box[][size],int aim){
    int row=0,col=0,s1=0,s2=0,i=0,j=0;
    for ( i=0 ; i<3 ; i++ ) {
        for ( j=0 ; j<3 ; j++ ){
            row+=box[i][j];
            col+=box[j][i];
        }
        s1+=box[i][i];
        s2+=box[i][size-i-1];
        if(row==aim||col==aim) return 1;
        row=0,col=0;
    }
    if(s1==aim||s2==aim) return 1;
    return 0;
}
void print(int box[][size]){
    int i,j;
    printf("-------------\n");
    for( i=0 ; i<3 ; i++ ){
        printf("|");
        for( j=0 ; j<3 ; j++ ){
            if(box[i][j]==0) printf("   |");
            if(box[i][j]==1) printf(" C |");
            if(box[i][j]==-1) printf(" P |");
        }
        printf("\n-------------\n");
    }
}
int winthegame(int box[3][3]){
    int i;
    for( i=0 ; i<9 ; i++ ){
        if(!box[i/3][i%3]){
            box[i/3][i%3]=1;
            if(count(box,3)) break;
            box[i/3][i%3]=0;
        }
    }
    printf("Computer win!\n");
    return i;
}
int notlose(int box[3][3]){
    int i;
    for( i=0 ; i<9 ; i++ ){
        if(!box[i/3][i%3]){
            box[i/3][i%3]=1;
            if(!count(box,-2)) break;
            box[i/3][i%3]=0;
        }
    }
    return i;
}
int trywin(int box[3][3]){
    int i;
    for( i=0 ; i<9 ; i++ ){
        if(!box[i/3][i%3]){
            box[i/3][i%3]=1;
            if(count(box,2)) break;
            box[i/3][i%3]=0;
        }
    }
    if(i==9) {
        for( i=0 ; i<9 ; i++ ){
            if(!box[i/3][i%3]){
                box[i/3][i%3]=1;
                break;
            }
        }
    }
    return i;
}
void sym(int box[][3],int i,int j){
    int a,b;
    if(i<2) a=2;
    else a=0;
    if(j<2) b=2;
    else b=0;
    box[a][b]=1;
    printf("COMP(%d,%d)\n",a,b);
    print(box);
}
void main(){
    int t=3,i,box[size][size]={0},row=1,col=1;
    box[1][1]=1;
    printf("COMP(%d,%d)\n",col,row);
    print(box);
    scanf("%d %d",&col,&row);
    printf("Player(%d,%d)\n",col,row);
    box[col][row]=-1;
    print(box);
    sym(box,col,row);
    while(t--){
        scanf("%d %d",&col,&row);
        if(box[col][row]){
            printf("error input\n");
            t++;
            continue;
        }
        box[col][row]=-1;
        printf("Player(%d,%d)\n",col,row);
        print(box);
        if(count(box,2)) i=winthegame(box);
        else if(count(box,-2)) i=notlose(box);
        else i=trywin(box);
        printf("COMP(%d,%d)\n",i/3,i%3);
        print(box);
        if(count(box,3)) return;
    }
    printf("FAIR!\n");
}
