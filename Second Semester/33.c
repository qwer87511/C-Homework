#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s node_t;
struct node_s {
	char data;
	node_t *right, *left;
};
node_t *createNode(char value) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}
node_t *build_PreIn(char *pre, char *in, int sum) {
	node_t *newnode = createNode(*pre);
	//if (sum == 1) return newnode;
	int index;
	for (index = 0; in[index] != *pre; index++);
	if (index > 0) newnode->left = build_PreIn(pre + 1, in, index);
	if (sum - index - 1 > 0) newnode->right = build_PreIn(pre + index + 1, in + index + 1, sum - index - 1);
	return newnode;
}
node_t *build_InPost(char *in, char *post, int sum) {
	node_t *newnode = createNode(post[sum - 1]);
	//if (sum == 1) return newnode;
	int index;
	for (index = 0; in[index] != post[sum - 1]; index++);
	if (index > 0) newnode->left = build_InPost(in, post, index);
	if (sum - index - 1 > 0) newnode->right = build_InPost(in + index + 1, post + index, sum - index - 1);
	return newnode;
}
void print_level(node_t *current, int x, int set) {
	if (x == set) {
		printf("%c", current->data);
		return;
	}
	if (current->left != NULL) print_level(current->left, x + 1, set);
	if (current->right != NULL) print_level(current->right, x + 1, set);
}
int main() {
	int i;
	char sel[3] = { 0 };
	char preorder[20] = { 0 }, inorder[20] = { 0 }, postorder[20] = { 0 };
	for (i = 0; i < 2; i++) {
		scanf("%s", &sel[i]);
		if (sel[i] == 'P') scanf("%s", preorder);
		else if (sel[i] == 'I') scanf("%s", inorder);
		else if (sel[i] == 'O') scanf("%s", postorder);
	}
	node_t *root;
	if (strchr(sel, 'P')) root = build_PreIn(preorder, inorder, strlen(inorder));
	else if (strchr(sel, 'O')) root = build_InPost(inorder, postorder, strlen(inorder));
	for (i = 0; i < 10; i++)
		print_level(root, 0, i);
}
