#include<stdio.h>
#include<string.h>
#define PRECISION 200 //Precision of output is 200, input is 100.//int 0~99 float 100~199
#define POINT PRECISION/2 //Position of point is 100
typedef enum { false, true } bool;
typedef struct {
	int digit[PRECISION];
	int decpt;
	int sign;
	int size;
} high_precision_t;
bool check_input(char in[]) {
	int len = strlen(in);
	if (len == 1) { if (isdigit(in[0]) == 0) return false; }
	else if (in[0] == '0' && in[1] != '.') return false;
	else if (in[len - 1] == '.') return false;
	else if (strchr(in, '.') != strrchr(in, '.')) return false;
	while (len--)
		if (isdigit(in[len]) == 0 && in[len] != '.')
			return false;
	return true;
}
void char_to_int(char *in, int *num) {//
	int i, int_len = strcspn(in, ".");
	strcpy(in + int_len, in + int_len + 1);
	for (i = 0; in[i] != '\0'; i++)
		num[POINT - int_len + i] = in[i] - '0';
}
bool input(int *num, int *sign) {
	char in[PRECISION + 2] = "\0", *ptr = in;
	scanf("%s", in);
	if (in[0] == '-') {
		*sign = -1;
		ptr = in + 1;
	}
	if (check_input(ptr) == false) return false;
	char_to_int(ptr, num);
	return true;
}
int unsigned_comparison(int *num1, int *num2) {
	int i;
	for (i = 0; i<PRECISION; i++) {
		if (num1[i]>num2[i]) return 1;
		if (num1[i]<num2[i]) return -1;
	}
	return 0;
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
	int i = 0, j = 0;
	for (i = POINT - 1; i >= 0; i--) {
		for (j = POINT - 1; j >= 0; j--) {
			res[i + j] += (num1[i] * num2[j] + res[i + j + 1]) / 10;
			res[i + j + 1] = (num1[i] * num2[j] + res[i + j + 1]) % 10;
		}
	}
}
void num_to_struct(high_precision_t *number, int *num, int sig) {
	number->sign = sig;
	number->size = 0;
	int i, j, n = 0;
	for (i = 0; num[i] == 0 && i < PRECISION; i++);
	for (j = PRECISION - 1; num[j] == 0 && j >= 0; j--);
	number->decpt = POINT - i;
	for (; i <= j; i++)
		number->digit[(number->size)++] = num[i];
}
void print_struct(high_precision_t number) {
	int i;
	printf("digit=");
	if (number.size == 0) printf("0");
	for (i = 0; i < number.size; i++)
		printf("%d", number.digit[i]);
	printf("\ndecpt=%d\n", number.decpt);
	printf("sign=%d\n", number.sign);
}
void compute(int *num1, int sign1, int *num2, int sign2, int *result, int *sign) {
    char ins;
	scanf(" %c", &ins);
	if (ins == 'm') {
		mul(num1 + PRECISION / 4, num2 + PRECISION / 4, result);
		*sign = sign1*sign2;
	}
	else {
		if (ins == 's') sign2 *= -1;
		if (sign1>0 && sign2>0) {
			add(num1, num2, result);
			*sign = 1;
		}
		else if (sign1<0 && sign2<0) {
			add(num1, num2, result);
			*sign = -1;
		}
		else if (unsigned_comparison(num1, num2) >= 0) {
			sub(num1, num2, result);
			if (sign2>0) *sign = -1;
		}
		else {
			sub(num1, num2, result);
			if (sign1>0) *sign = -1;
		}
	}
}
int main() {
	high_precision_t number;
	int num1[PRECISION] = { 0 }, num2[PRECISION] = { 0 }, result[PRECISION] = { 0 };
	int sign1 = 1, sign2 = 1, sign = 1;
	if (input(num1, &sign1) == false || input(num2, &sign2) == false) {
		printf("input error\n");;
		return -1;
	}
	compute(num1, sign1, num2, sign2, result, &sign);
	num_to_struct(&number, result, sign);
	print_struct(number);;
}
