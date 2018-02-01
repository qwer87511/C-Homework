#include<stdio.h>
void maximum (int *grade){
    int max=*grade,i;
    for( i=0 ; i<90 ; i++ ){
        if(max<*(grade+i))
            max=*(grade+i);
    }
    printf("%d\n",max);
}
int maxpos (int *grade){
    int max=*grade,i,p=0;
    for( i=0 ; i<90 ; i++ ){
        if(max<*(grade+i)){
            max=*(grade+i);
            p=i;
        }
    }
    return p;
}
void minimum (int *grade){
    int min=*grade,i;
    for( i=0 ; i<90 ; i++ ){
        if( min>*(grade+i) && *(grade+i) ) min=*(grade+i);
    }
    printf("%d\n",min);
}
void notposs(int *id, int *grade){
    int i;
    for( i=0 ; i<90 ; i++){
        if(*(grade+i)<60 && *(grade+i)) printf("%d:%d\n",*(id+i),*(grade+i));
    }
}
void poss(int *id, int *grade){
    int i;
    for( i=0 ; i<90 ; i++){
        if(*(grade+i)>=60 && *(grade+i)) printf("%d:%d\n",*(id+i),*(grade+i));
    }
}
void rank(int *id, int *grade){
    int i;
    printf("1st:%d %d\n",*(id+maxpos(grade)),*(grade+maxpos(grade)));
    *(grade+maxpos(grade))=0;
    printf("2nd:%d %d\n",*(id+maxpos(grade)),*(grade+maxpos(grade)));
    *(grade+maxpos(grade))=0;
    printf("3rd:%d %d\n",*(id+maxpos(grade)),*(grade+maxpos(grade)));
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void mid(int *grade, int i){
    int k=0,j=0;
    for( k=0 ; k<90 ; k++ ){
        for ( j=k ; j>0 ; j-- ){
            if(*(grade+j)>*(grade+j-1)){
                swap(grade+j,grade+j-1);
            }
        }
    }
    if(i%2) printf("%d\n",*(grade+((i-1)/2)));
    else printf("%d\n",(*(grade+i/2)+*(grade+i/2-1))/2);
}
void graph(int *grade){
    int i=0,margin=10;
    for( margin=10 ; margin<=100 ; margin+=10 ){
        if (margin==10) printf("%d-%d:",margin-10,margin);
        else printf("%d-%d:",margin-9,margin);
        for( i=0 ; i<90 ; i++ ){
            if( margin-10<*(grade+i) && *(grade+i)<=margin ) printf("*");
        }
        printf("\n");
    }
}
int main(){
    int id[90]={0}, cs[90]={0}, gp[90]={0}, average[90]={0}, i=0 , j=0, ins=0, in=0, pos=0;
    for( i=0 ; i<90 ; i++){
        scanf("%d",&id[i]);
        if (id[i]==-1) break;
        scanf("%d %d",&cs[i],&gp[i]);
        average[i]=(cs[i]+gp[i])/2;
        for ( j=i ; j>0 ; j-- ){
            if(id[j]<id[j-1]){
                swap(&id[j],&id[j-1]);
                swap(&cs[j],&cs[j-1]);
                swap(&gp[j],&gp[j-1]);
                swap(&average[j],&average[j-1]);
            }
        }
    }
    scanf("%d %d",&ins,&in);
    if ( ins==1 ){
        int q=0;
        scanf("%d",&q);
        for( j=0 ; j<90 ; j++){
            if(id[j]==q) break;
        }
        if (in==1) printf("%d\n",average[j]);
        if (in==2) printf("%d\n",cs[j]);
        if (in==3) printf("%d\n",gp[j]);
    }
    if ( ins==2 ){
        if (in==1) maximum(average);
        if (in==2) maximum(cs);
        if (in==3) maximum(gp);
    }
    if ( ins==3 ){
        if (in==1) minimum(average);
        if (in==2) minimum(cs);
        if (in==3) minimum(gp);
    }
    if ( ins==4 ){
        if (in==1) notposs(id,average);
        if (in==2) notposs(id,cs);
        if (in==3) notposs(id,gp);
    }
    if ( ins==5 ){
        if (in==1) poss(id,average);
        if (in==2) poss(id,cs);
        if (in==3) poss(id,gp);
    }
    if ( ins==6 ){
        if (in==1) rank(id,average);
        if (in==2) rank(id,cs);
        if (in==3) rank(id,gp);
    }
    if ( ins==7 ){
        if (in==1) mid(average,i);
        if (in==2) graph(average);
    }
}
