#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 16
typedef struct node_s node_t;
struct node_s {
	int data;
	node_t *next;
};
typedef struct queue_node_s queue_node_t;
struct queue_node_s {
	char name[NAME_SIZE];
	node_t *front, *rear;
	queue_node_t *next;
};
queue_node_t *createQueue() {
	queue_node_t *newqueue = (queue_node_t*)malloc(sizeof(queue_node_t));
	scanf("%s", newqueue->name);
	newqueue->front = newqueue->rear = NULL;
	newqueue->next = NULL;
	return newqueue;
}
void createNewQueue(queue_node_t **queue_front, queue_node_t **queue_rear) {
	if (*queue_front == NULL) *queue_front = *queue_rear = createQueue();
	else *queue_rear = (*queue_rear)->next = createQueue();
}
queue_node_t *findQueue(queue_node_t *queue_node, char *inname) {
	for (; queue_node != NULL; queue_node = queue_node->next)
		if (strcmp(queue_node->name, inname) == 0)
			return queue_node;
	return NULL;
}
node_t *createNode(int value) {
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}
void enQueue(node_t **front, node_t **rear, int value) {
	if (*front == NULL) *front = *rear = createNode(value);
	else *rear = (*rear)->next = createNode(value);
}
void tryEnQueue(queue_node_t *queue_front) {
	char inname[NAME_SIZE];
	scanf("%s", inname);
	int value;
	scanf("%d", &value);
	queue_node_t *foundQueue = findQueue(queue_front, inname);
	if (foundQueue != NULL) enQueue(&foundQueue->front, &foundQueue->rear, value);
	else printf("Queue %s isn't exist\n", inname);
}
void deQueue(node_t **front, node_t **rear) {
	node_t *temp = *front;
	if (*front == *rear) *front = *rear = NULL;
	else *front = (*front)->next;
	free(temp);
}
void tryDeQueue(queue_node_t *queue_front) {
	char inname[NAME_SIZE];
	scanf("%s", inname);
	queue_node_t *foundQueue = findQueue(queue_front, inname);
	if (foundQueue == NULL) printf("Queue %s isn't exist\n", inname);
	else if (foundQueue->front == NULL) printf("Queue is empty\n");
	else deQueue(&foundQueue->front, &foundQueue->rear);
}
void mergeQueue(queue_node_t **queue1, queue_node_t *queue2) {
	if ((*queue1)->front == NULL) (*queue1)->front = queue2->front;
	else (*queue1)->rear->next = queue2->front;
	(*queue1)->rear = queue2->rear;
}
void deleteQueue(queue_node_t **queue_front, queue_node_t **queue_rear, queue_node_t *queue) {
	if (*queue_front == queue)
		*queue_front = (*queue_front)->next;
	else {
		queue_node_t *prev;
		for (prev = *queue_front; prev->next != queue; prev = prev->next);
		prev->next = queue->next;
		if (*queue_rear == queue) *queue_rear = prev;
	}
	free(queue);
}
void tryMergeQueue(queue_node_t **queue_front, queue_node_t **queue_rear) {
	char queue1[NAME_SIZE], queue2[NAME_SIZE];
	scanf("%s%s", queue1, queue2);
	queue_node_t *foundQueue1 = findQueue(*queue_front, queue1);
	queue_node_t *foundQueue2 = findQueue(*queue_front, queue2);
	if (foundQueue1 == NULL) printf("Queue %s isn't exist\n", queue1);
	if (foundQueue2 == NULL) printf("Queue %s isn't exist\n", queue2);
	if (foundQueue1 != NULL && foundQueue2 != NULL && foundQueue2->front != NULL)
		mergeQueue(&foundQueue1, foundQueue2);
	if (foundQueue2 != NULL)
		deleteQueue(queue_front, queue_rear, foundQueue2);
}
size_t countNodeSize(node_t *node) {
	size_t size = 0;
	for (; node != NULL; node = node->next)
		size++;
	return size;
}
void printAllQueue(queue_node_t *queue) {
	printf("****************************************\n");
	if (queue == NULL) printf("Isn't have any queue\n");
	else {
		queue_node_t *queue_ptr;
		node_t *node_ptr;
		for (queue_ptr = queue; queue_ptr != NULL; queue_ptr = queue_ptr->next) {
			int size = countNodeSize(queue_ptr->front);
			printf("Queue Name:%s Queue Size:%d Queue Element:", queue_ptr->name, size);
			if (size == 0) printf("Queue is empty");
			for (node_ptr = queue_ptr->front; node_ptr != NULL; node_ptr = node_ptr->next)
				printf("%d ", node_ptr->data);
			printf("\n");
		}
	}
	printf("****************************************\n");
}
void run() {
	queue_node_t *queue_front = NULL, *queue_rear = NULL;
	int select = 0;
	while (select != 6) {
		scanf("%d", &select);
		if (select == 1) createNewQueue(&queue_front, &queue_rear);
		else if (select == 2) tryEnQueue(queue_front);
		else if (select == 3) tryDeQueue(queue_front);
		else if (select == 4) tryMergeQueue(&queue_front, &queue_rear);
		else if (select == 5) printAllQueue(queue_front);
	}
}
int main() {
	run();
}
