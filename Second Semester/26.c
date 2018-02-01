#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node node_t;
struct _node{
	int data;
	node_t *next;
};
node_t *createNode(int value) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void push(node_t *node, int value) {
	int temp = node->data;
	node->data = value;
	while (node->next != NULL) {
		swap(&temp, &node->next->data);
		node = node->next;
	}
	node->next = createNode(temp);
}
void input(node_t *node) {
	char in[50] = "\0", *ptr;
	gets(in);
	node->data = atoi(strtok(in, " "));
	while ((ptr = strtok(NULL, " ")) != NULL)
		push(node,atoi(ptr));
}
int main() {
	node_t *head1, *tail1, *head2, *tail2, *head3, *tail3;
	tail1 = head1 = createNode(0);
	tail2 = head2 = createNode(0);
	input(head1);
	input(head2);
	printf("%d %d %d", head1->data, head1->next->data, head1->next->next->data);
}
