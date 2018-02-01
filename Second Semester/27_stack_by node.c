#include <stdio.h>
#include <stdlib.h>
typedef struct _node node_t;
struct _node {
	int data;
	node_t *next;
};
node_t *createNode(int value) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}
node_t *push(node_t *oldTop) {
	int value;
	scanf("%d", &value);
	node_t *newTop = createNode(value);
	newTop->next = oldTop;
	return newTop;
}
node_t *pop(node_t *oldTop) {
	printf("The data %d is pop\n", oldTop->data);
	node_t *newTop = oldTop->next;
	free(oldTop);
	return newTop;
}
void run() {
	node_t *top = NULL;
	int select = 0;
	while (select != 3) {
		scanf("%d", &select);
		if (select == 1) top = push(top);
		else if (select == 2) {
			if (top == NULL) printf("The Stack is empty\n");
			else top = pop(top);
		}
	}
}
node_t *create(){
    return *node_t;
}
int main() {
	node_t *node=(node_t*)malloc(sizeof(node_t));
}
