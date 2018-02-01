#include<stdio.h>
void stack(int *memory){
    int ins,data,top=-1,j;
    while(1){
        scanf("%d",&ins);
        switch(ins){
            case 1:
                if(top==4) {
                    printf("FULL\n");
                    return;
                }
                scanf("%d",&data);
                memory[++top]=data;
                break;
            case 2:
                if(top==-1) {
                    printf("EMPTY\n");
                    return;
                }
                top--;
                break;
            case 3:
                for( j=0 ; j<=top ; j++ ) printf("%d ",*(memory+j));
                return;
        }
    }
}
void queue(int *memory){
    int ins,data,i=0,j,front=0,rear=0;
    while(1){
        scanf("%d",&ins);
        switch(ins){
            case 1:
                if( front==0&&rear==4 || front==rear+1 ){
                    printf("FULL\n");
                    return;
                }
                rear++;
                if(rear==5) rear=0;
                scanf("%d",&data);
                memory[rear]=data;
                break;
            case 2:
                if(front==rear){
                    printf("EMPTY\n");
                    return;
                }
                front++;
                if(front==5) front=0;
                memory[front]=0;
                break;
            case 3:
                for( j=front+1 ; j<=rear+5 ; j++ ) printf("%d ",*(memory+j%5));
                return;
        }
    }
}
int main(){
    int memory[5]={0},type=0;
    scanf("%d",&type);
    if(type==1) stack(memory);
    else queue(memory);
}
