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
node_t *putInFront(node_t *node, int value) {
	node_t *newnode = createNode(value);
	newnode->next = node;
	return newnode;
}
node_t *input(node_t *node) {
	char in[50] = "\0", *ptr;
	gets(in);
	node->data = atoi(strtok(in, " "));
	while ((ptr = strtok(NULL, " ")) != NULL)
		node = putInFront(node,atoi(ptr));
	return node;
}
node_t *add(node_t *equ1, node_t *equ2) {
	node_t *head, *tail;
	head = tail = createNode(equ1->data + equ2->data);
	if (equ1 != NULL) equ1 = equ1->next;
	if (equ2 != NULL) equ2 = equ2->next;
	while (equ1 != NULL || equ2 != NULL) {
		tail = tail->next = createNode(0);
		if (equ1 != NULL) tail->data += equ1->data;
		if (equ2 != NULL) tail->data += equ2->data;
		if (equ1 != NULL) equ1 = equ1->next;
		if (equ2 != NULL) equ2 = equ2->next;
	}
	return head;
}
void reverseOutput(node_t *node) {
	if (node == NULL) return;
	reverseOutput(node->next);
	printf("%d ", node->data);
}
int main() {
	node_t *head1, *head2, *result;
	head1 = createNode(0);
	head2 = createNode(0);
	head1 = input(head1);
	head2 = input(head2);
	result = add(head1, head2);
	reverseOutput(result);
}
