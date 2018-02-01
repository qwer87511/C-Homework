#include <stdio.h>
#include <string.h>
#define PRECISION 200 //Precision of output is 200, input is 100.//int 0~99 float 100~199
#define POINT PRECISION/2 //Position of point is 100
void print(int *num) {
	int i, j;
	for (i = 0; num[i] == 0 && i < POINT; i++);
	if (i == POINT) printf("0");
	for (; i < POINT; i++)
		printf("%d", num[i]);
	for (i = PRECISION - 1; num[i] == 0 && i >= POINT; i--);
	if (i != POINT - 1) printf(".");
	for (j = POINT; j <= i; j++)
		printf("%d", num[j]);
	printf("\n");
}
void input(int *num) {
	char in[PRECISION] = "\0";
	scanf("%s", in);
	int temp = 0, i, intLen = strlen(strtok(in, "."));
	for (i = POINT - intLen; in[temp] != '\0'; i++) {
		num[i] = in[temp++] - '0';
		if (i == POINT - 1) temp++;
	}
	//print(num);
}
void add(int *num1, int *num2, int *res) {
	int i = 0, j = 0;
	for (i = PRECISION - 1; i >= 0; i--) {
		res[i - 1] += (num1[i] + num2[i] + res[i]) / 10;
		res[i] = (num1[i] + num2[i] + res[i]) % 10;
	}
}
void sub(int *num1, int *num2, int *res) {
	int i = 0, j = 0;
	for (i = PRECISION - 1; i >= 0; i--) {
		if ((num1[i] + res[i]) < num2[i]) {
			res[i - 1]--;
			res[i] += 10;
		}
		res[i] += num1[i] - num2[i];
	}
}
void mul(int *num1, int *num2, int *res) {//Both precision of input are 100 , output is 200
	num1 += PRECISION / 4; //shift to 1/4 to 3/4
	num2 += PRECISION / 4;
	int i = 0, j = 0;
	for (i = POINT - 1; i >= 0; i--) {
		for (j = POINT - 1; j >= 0; j--) {
			res[i + j] += (num1[i] * num2[j] + res[i + j + 1]) / 10;
			res[i + j + 1] = (num1[i] * num2[j] + res[i + j + 1]) % 10;
		}
	}
}
int comp(int *num1, int *num2){
    int i;
    for (i = 0; i<PRECISION; i++) {
		if (num1[i]>num2[i]) return 1;
		if (num1[i]<num2[i]) return -1;
	}
	return 0;
}
int main() {
	int num1[PRECISION] = { 0 }, num2[PRECISION] = { 0 }, res[PRECISION] = { 0 };
	input(num1);
	input(num2);
	add(num1, num2, res);
	print(res);
	memset(res, 0, sizeof(int)*PRECISION);
	sub(num1, num2, res);
	print(res);
	memset(res, 0, sizeof(int)*PRECISION);
	mul(num1, num2, res);
	print(res);
}
