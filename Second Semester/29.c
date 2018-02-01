#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int id; //�Ǹ�
	int score; //����
} student_t;
typedef struct node {
	student_t data;
	struct node *next;
} node_t,*nodep_t;
void printList(nodep_t p) { // �L�X List ���e
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
void insertInOrder(nodep_t *p, student_t data) { // �[�J���᪺LIST�O�̷ӥѤp��j���ƶ��Ǫ��A�èϥΰj���@
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
	printf("Insert data %d:%d, compare:%d.\n", data.id, data.score, times);
}
nodep_t findPreviousNode(nodep_t p, int ask_id) {
	for (; p->next != NULL; p = p->next)
		if (p->next->data.id == ask_id)
			return p;
	return NULL;
}
void deleteStudent(nodep_t *p, int ask_id) { // �R���S�w�Ǹ������
	if (*p == NULL) printf("Student %d is not exist.\n", ask_id);
	else if ((*p)->data.id == ask_id) {
		nodep_t temp = *p;
		*p = (*p)->next;
		free(temp);
		printf("Delete student %d successful.\n", ask_id);
	}
	else {
		nodep_t found = findPreviousNode(*p, ask_id);
		if (found != NULL) {
			nodep_t temp = found->next;
			found->next = found->next->next;
			free(temp);
			printf("Delete student %d successful.\n", ask_id);
		}
		else printf("Student %d is not exist.\n", ask_id);
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
			int deleteid;
			scanf("%d", &deleteid);
			deleteStudent(&head, deleteid);
		}
	}
}
