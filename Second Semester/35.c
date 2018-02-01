#include <stdio.h>
#include <stdlib.h>
typedef struct node_s {
	char data;
	struct node_s *left, *mid, *right;
} node_t;
node_t *createNode(char data) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = data;
	newnode->left = newnode->mid = newnode->right = NULL;
	return newnode;
}
node_t *find(node_t *node, char aim) {
	if (node == NULL) return NULL;
	if (node->data == aim) return node;
	if (find(node->left, aim)) return find(node->left, aim);
	else if (find(node->mid, aim)) return find(node->mid, aim);
	else if (find(node->right, aim)) return find(node->right, aim);
	return NULL;
}
void build(node_t *root, char *data) {
	node_t *found = find(root, *data);
	int i;
	for (i = 1; data[i] != '\0'; i++) {
		if (!found->left) found->left = createNode(data[i]);
		else if (!found->mid) found->mid = createNode(data[i]);
		else found->right = createNode(data[i]);
	}
}
void swapPtr(node_t **a, node_t **b) {
	node_t *temp = *a;
	*a = *b;
	*b = temp;
}
void getSeq(node_t *node, node_t **ptr) {
	ptr[0] = node->left;
	ptr[1] = node->mid;
	ptr[2] = node->right;
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2 - i; j++)
			if (ptr[j + 1])
				if (ptr[j]->data > ptr[j + 1]->data)
					swapPtr(ptr + j, ptr + j + 1);
}
void print(node_t *node) {
	node_t *ptr[3] = { NULL };
	getSeq(node, ptr);
	printf("%c", node->data);
	if (ptr[0]) print(ptr[0]);
	if (ptr[1]) print(ptr[1]);
	if (ptr[2]) print(ptr[2]);
}
int main() {
	node_t *root = NULL;
	char sel = 0;
	while (sel != 'e') {
		scanf("%c", &sel);
		if (sel == 'i') {
			char data[5];
			scanf(" %s", data);
			if (root == NULL) root = createNode(*data);
			build(root, data);
		}
		else if (sel == 'p') {
			if (root) print(root);
			else printf("null");
			printf("\n");
		}
	}
}
