#include<stdio.h>
#include<stdbool.h>
int getAtt(char Attributes[7][3], char in[2])
{
	scanf("%c", in + 1);
	int i;
	for (i = 0; i<7; i++)
		if (*in == *Attributes[i] && in[1] == Attributes[i][1])
			return i + 1;
}
void get1(char Attributes[7][3], char name[11][11], int att[11][11], int *num)
{
	int i, j = 0;
	char in[2];
	scanf("%d ", num);
	for (i = 0; i<*num; i++) {
		scanf("%s ", name[i]);
		for (j = 0;;) {
			scanf("%c", in);
			if (*in == '\n')
				break;
			else if (*in >= 'A' && *in <= 'Z')
				att[i][j++] = getAtt(Attributes, in);
		}
	}
}
void get2(char Attributes[7][3], int inq[11][11])
{
	int i, j;
	char in[2];
	for (i = 0;; i++) {
		for (j = 0;;) {
			scanf("%c", in);
			if (*in == '+')
				break;
			else if (*in == '\n')
				return;
			else if (*in >= 'A' && *in <= 'Z')
				inq[i][j++] = getAtt(Attributes, in);
		}
	}
}
int cmp(int att[11], int inq[11])
{
	int i, j;
	for (i = 0; i<11; i++) {
		if (inq[i] == 0) return 1;
		for (j = 0; j<11; j++) {
			if (inq[i] == att[j])
				break;
		}
		if (j == 11)
			return 0;
	}
}
void search(int inq[11][11], int att[11][11], char name[11][11])
{
	int i, j;
	for (i = 0; i<11; i++) {
		if (att[i][0] == 0)
			return;
		for (j = 0; j<11; j++) {
			if (inq[j][0] && cmp(att[i], inq[j])) {
				printf("%s ", name[i]);
				break;
			}
		}
	}
}
int main()
{
    bool a=true;
	char Attributes[7][3] = { "BC", "NC", "CT", "NS", "NM", "HL", "NL" };
	char name[11][11];
	int num, att[11][11] = { 0 }, inq[11][11] = { 0 }, times;
	int i, j;
	get1(Attributes, name, att, &num);
	scanf("%d ", &times);
	while (times--) {
		for (i = 0; i<11; i++) for (j = 0; j<11; j++) inq[i][j] = 0;
		get2(Attributes, inq);
		search(inq, att, name);
		printf("\n");
	}
}
