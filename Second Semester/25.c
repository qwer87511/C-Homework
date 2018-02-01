#include <stdio.h>
#include <string.h>
typedef enum { false, true } bool;
typedef struct {
	char name[9];
	char password[9];
	bool voted;
} user_t;
typedef struct {
	char name[9];
	int id;
	int votes;
} cand_t;
bool legalUsername(user_t *user, int num, char *newname) {
	while (num--)
		if (strcmp(user[num].name, newname) == 0)
			return false;
	int len = strlen(newname);
	if (len != 8) return false;
	while (len--)
		if (!isalpha(newname[len]) && !isdigit(newname[len]))
			return false;
	return true;
}
bool legalPassword(char *word, char *name) {
	if (strcmp(word, name) == 0) return false;
	int len = strlen(word);
	if (len < 1 || len>8) return false;
	while (len--)
		if (!isalpha(word[len]) && !isdigit(word[len]) && word[len] != '_' && word[len] != '-' && word[len] != '@' && word[len] != '#' && word[len] != '%')
			return false;
	return true;
}
void addUser(user_t *user, int *sum, char *in) {
	char *newname = strtok(in, ",");
	char *word = strtok(NULL, ",");
	if (!legalUsername(user, *sum, newname)) printf("Add user error\nusername error\n");
	else if (!legalPassword(word, newname)) printf("Add user error\npassword error\n");
	else {
		strcpy(user[*sum].name, newname);
		strcpy(user[*sum].password, word);
		user[*sum].voted = false;
		(*sum)++;
		printf("Add user successful\n");
	}
}
bool NewCandidate(cand_t *cand, int sum, int num, char *newname) {
	while (sum--) {
		if (cand[sum].id == num) return false;
		if (strcmp(cand[sum].name, newname) == 0) return false;
	}
	return true;
}
void addCandidate(cand_t *cand, int *sum, user_t manager, char *in) {
	char *inName = strtok(in, ",");
	char *inPassword = strtok(NULL, ",");
	int candNum = atoi(strtok(NULL, ","));
	char *candName = strtok(NULL, "\0");
	if (strcmp(inName, manager.name) != 0) printf("Login error\n");
	else if (strcmp(inPassword, manager.password) != 0) printf("Login error\n");
	else if (!NewCandidate(cand, *sum, candNum, candName)) printf("Candidate data error\n");
	else {
		strcpy(cand[*sum].name, candName);
		cand[*sum].id = candNum;
		cand[*sum].votes = 0;
		(*sum)++;
		printf("Add candidate successful\n");
	}
}
int logIn(user_t *user, int sum, char *inName, char *inPasswd) {
	while (sum--)
		if (strcmp(user[sum].name, inName) == 0)
			if (strcmp(user[sum].password, inPasswd) == 0)
				return sum;
	return -1;
}
int candidateId(cand_t *cand, int sum, int candNum) {
	while (sum--)
		if (cand[sum].id == candNum)
			return sum;
	return -1;
}
void voting(user_t *user, int sum_u, cand_t *cand, int sum_c, char *in) {
	char *inName = strtok(in, ",");
	char *inPasswd = strtok(NULL, ",");
	int candNum = atoi(strtok(NULL, "\0"));
	int userId = logIn(user, sum_u, inName, inPasswd);
	int candId = candidateId(cand, sum_c, candNum);
	if (userId == -1) printf("Login error\n");
	else if (strcmp(user[0].name, inName) == 0 || user[userId].voted == true) printf("Voting error\n");
	else if (candId == -1) printf("Candidate error\n");
	else {
		cand[candId].votes++;
		user[userId].voted = true;
		printf("Voting successful\n");
	}
}
void output(user_t *user, int sum_u, cand_t *cand, int sum_c, char *in) {
	char *inName = strtok(in, ",");
	char *inPasswd = strtok(NULL, "\0");
	if (logIn(user, sum_u, inName, inPasswd) == -1) printf("Login error\n");
	else {
		int i;
		for (i = 0; i < sum_c - 1; i++)
			printf("(%d,%s,%d),", cand[i].id, cand[i].name, cand[i].votes);
		printf("(%d,%s,%d)", cand[i].id, cand[i].name, cand[i].votes);
	}
	printf("\n");
}
int main() {
	user_t user[20];
	cand_t cand[20];
	int sum_u = 0, sum_c = 0;
	char in[50] = "\0";
	while (in[0] != 'E') {
		scanf("%s", in);
		if (in[0] == 'A') addUser(user, &sum_u, in + 2);
		else if (in[0] == 'M') addCandidate(cand, &sum_c, user[0], in + 2);
		else if (in[0] == 'V') voting(user, sum_u, cand, sum_c, in + 2);
		else if (in[0] == 'Q') output(user, sum_u, cand, sum_c, in + 2);
	}
	printf("Exit\n");
}
