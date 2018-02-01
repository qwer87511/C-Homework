#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int id; //學號
	int score; //分數
} student_t;
typedef struct node {
	student_t data;
	struct node *next;
} node_t,*nodep_t;
void printList(nodep_t p) { // 印出 List 內容
	if (p == NULL) printf("null\n");
	else {
		for (; p->next != NULL; p = p->next)
			printf("%d:%d,", p->data.id, p->data.score);
		printf("%d:%d\n", p->data.id, p->data.score);
	}
}
bool isLess(student_t stu1, student_t stu2, int *times) {
	(*times)++;
	if (stu1.score < stu2.score || stu1.score == stu2.score && stu1.id < stu2.id)
		return true;
	return false;
}
nodep_t createNode(student_t data) {
	nodep_t newnode = (nodep_t)malloc(sizeof(node_t));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
nodep_t findPreviousData(nodep_t ptr, student_t data, int *times) {
	for (; ptr->next != NULL; ptr = ptr->next)
		if (isLess(data, ptr->next->data, times))
			break;
	return ptr;
}
void insertInOrder(nodep_t *p, student_t data) { // 加入之後的LIST是依照由小到大分數順序的，並使用迴圈實作
	int times = 0;
	if (*p == NULL) *p = createNode(data);
	else { //insert
		nodep_t newnode = createNode(data);
		if (isLess(data, (*p)->data, &times)) {
			newnode->next = *p;
			*p = newnode;
		}
		else {
			nodep_t previous = findPreviousData(*p, data, &times);
			newnode->next = previous->next;
			previous->next = newnode;
		}
	}
	printf("Insert data %d:%d, Compare:%d, Recursive:%d.\n", data.id, data.score, times, times + 1);
}
nodep_t findPrevStu(nodep_t p, int score) {
	for (; p->next != NULL; p = p->next)
		if (p->next->data.score >= score)
			break;
	return p;
}
void freeAll(nodep_t p) {
	printf("Delete student %d:%d successful.\n", p->data.id, p->data.score);
	if (p->next != NULL) freeAll(p->next);
	free(p);
}
void deleteStudent(nodep_t *p, int score) { //刪除List中大於等於輸入分數的學生
	if ((*p)->data.score >= score) {
		freeAll(*p);
		*p = NULL;
	}
	else {
		nodep_t prev = findPrevStu(*p, score);
		if (prev->next != NULL) freeAll(prev->next);
		else printf("No student greater or equal to score:%d.\n", score);
		prev->next = NULL;
	}
}
int main() {
	nodep_t head = NULL;
	char select = '\0';
	while (select != 'e') {
		scanf("%c", &select);
		if (select == 'p') printList(head);
		else if (select == 'i') {
			student_t newstudent;
			scanf("%d,%d", &newstudent.id, &newstudent.score);
			insertInOrder(&head, newstudent);
		}
		else if (select == 'd') {
			int score;
			scanf("%d", &score);
			deleteStudent(&head, score);
		}
	}
}
