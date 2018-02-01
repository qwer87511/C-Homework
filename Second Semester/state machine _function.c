#include<stdio.h>
#include<math.h>
typedef enum {false, true} bool;
typedef struct {
    int digit[40];
    int decpt;
    int sign;
} high_precision_t;
bool stateMachine(high_precision_t *num, int *sum) {
	bool ret = true;
	int sign = 1, state = 0, dot = 1, i = 0;
	double result = 0.0;
	char in[50];
	scanf("%s", &in);
	for (;; i++) {
		////////////////////////////////////////////////////////
		if (state == 0 && isdigit(in[i]) && in[i] != '0') {
			state = 1;
			result += in[i] - '0';
			num->digit[(*sum)++] = in[i] - '0';
		}
		else if (state == 0 && in[i] == '0') {
			num->digit[(*sum)++] = in[i] - '0';
			state = 4;
		}
		else if (state == 0 && in[i] == '-') {
			sign = -1;
			state = 5;
		}
		////////////////////////////////////////////////////////
		else if (state == 1 && isdigit(in[i])) {
			result *= 10;
			result += in[i] - '0';
			num->digit[(*sum)++] = in[i] - '0';
		}
		else if (state == 1 && in[i] == '.') {
			state = 2;
		}
		////////////////////////////////////////////////////////
		else if (state == 2 && isdigit(in[i])) {
			state = 3;
			result += (in[i] - '0')*pow(10, -dot);
			dot++;
			num->digit[(*sum)++] = in[i] - '0';
		}
		else if (state == 2 && in[i] == '\0') {
			printf("error");
			ret = false;
		}
		////////////////////////////////////////////////////////
		else if (state == 3 && isdigit(in[i])) {
			result += (in[i] - '0')*pow(10, -dot);
			dot++;
			num->digit[(*sum)++] = in[i] - '0';
		}
		////////////////////////////////////////////////////////
		else if (state == 4 && in[i] == '.') {
			state = 2;
		}
		else if (state == 4 && in[i] == '\0'&&sign == -1) {
			printf("error");
			ret = false;
		}
		////////////////////////////////////////////////////////
		else if (state == 5 && isdigit(in[i]) && in[i] != '0') {
			state = 1;
			result *= 10;
			result += in[i] - '0';
			num->digit[(*sum)++] = in[i] - '0';
		}
		else if (state == 5 && in[i] == '0') {
			num->digit[(*sum)++] = in[i] - '0';
			state = 4;
		}
		else if (state == 5 && in[i] == '\0') {
			printf("error");
			ret = false;
		}
		//////////////////////////////////////////////////////////
		else if (in[i] == '\0') {
			break;
		}
		else {
			printf("error\n");
			ret = false;
		}
	}
	dot--;
	num->decpt = *sum - dot;
	num->sign = sign;
	result *= sign;
	//printf("%.*f\n",dot,result);
	for (i = 0; i<40; i++) printf("%d", num->digit[i]);
	printf("\n%d\n", num->decpt);
	printf("\n%d\n", num->sign);
	return ret;
}
bool stateMachine2(char *num){
    bool ret = true;
    int sign=1,state=0,dot=1,i=0;
    double result=0.0;
    for(;;i++){
////////////////////////////////////////////////////////
        if(state==0&&isdigit(num[i])&&num[i]!='0'){
            state=1;
            result+=num[i]-'0';
        }
        else if(state==0&&num[i]=='0'){
            state=4;
        }
        else if(state==0&&num[i]=='-'){
            sign=-1;
            state=5;
        }
////////////////////////////////////////////////////////
        else if(state==1&&isdigit(num[i])){
            result*=10;
            result+=num[i]-'0';
        }
        else if(state==1&&num[i]=='.'){
            state=2;
        }
////////////////////////////////////////////////////////
        else if(state==2&&isdigit(num[i])){
            state=3;
            result+=(num[i]-'0')*pow(10,-dot);
            dot++;
        }
        else if(state==2&&num[i]=='\0'){
            printf("error");
            ret = false;
        }
////////////////////////////////////////////////////////
        else if(state==3&&isdigit(num[i])){
            result+=(num[i]-'0')*pow(10,-dot);
            dot++;
        }
////////////////////////////////////////////////////////
        else if(state==4&&num[i]=='.'){
            state=2;
        }
        else if(state==4&&num[i]=='\0'&&sign==-1){
                printf("error");
                ret = false;
        }
////////////////////////////////////////////////////////
        else if(state==5&&isdigit(num[i])&&num[i]!='0'){
            state=1;
            result*=10;
            result+=num[i]-'0';
        }
        else if(state==5&&num[i]=='0'){
            state=4;
        }
        else if(state==5&&num[i]=='\0'){
                printf("error");
                ret = false;
        }
        else if(num[i]=='\0'){
            break;
        }
        else{
            printf("error\n");
            ret = false;
        }
    }
    dot--;
    result*=sign;
    printf("%.*f\n",dot,result);
    return ret;
}
int main(){
    char in[50]="0.0";
    stateMachine2(in);
}
