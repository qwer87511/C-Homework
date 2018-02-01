#include <stdio.h>
#include <stdlib.h>
typedef struct node_s node_t;
struct node_s {
	int data;
	node_t *left, *right;
};
node_t *createNode(int value) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}
void build(node_t *node,int data) {
	if (data < node->data) {
		if (node->left == NULL) node->left = createNode(data);
		else build(node->left, data);
	}
	else {
		if (node->right == NULL) node->right = createNode(data);
		else build(node->right, data);
	}
}
void print_inorder(node_t *current) {
	if (current == NULL) return;
	if (current->left) print_inorder(current->left);
	printf("%d ", current->data);
	if (current->right) print_inorder(current->right);
}
int main() {
	char sel = 0;
	int data;
	node_t *root = NULL;
	while (sel != 'e') {
		scanf("%c", &sel);
		if (sel == 'i') {
			scanf(" %d", &data);
			if (root == NULL) root = createNode(data);
			else build(root, data);
		}
		else if (sel == 'p') {
			if (root == NULL) printf("null");
			else print_inorder(root);
			printf("\n");
		}
	}
}/*i 10 i 15 i 5 i 12 i 17 i 7 i 3 e*/
