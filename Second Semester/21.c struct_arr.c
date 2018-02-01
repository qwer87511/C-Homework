#include<stdio.h>
#include<string.h>
typedef struct internet{
	int ip[4];
	char name[20];
} netdata;
int errorRange(int ip[4]){
	int i;
	for (i = 0; i < 4; i++)
		if (ip[i] > 255 || ip[i] < 0)
			return 1;
	return 0;
}
void input(netdata net[20], int *sum){
	for (;; (*sum)++) {
		scanf("%d.%d.%d.%d,%s", net[*sum].ip, net[*sum].(ip+1) , net[*sum].(ip+2), net[*sum].(ip+3), net[*sum].name);
		if (errorRange((net + *sum) ->ip))
			(net + *sum) ->ip[0] = -2;
		if (strcmp((net + *sum) -> name, "none") == 0 && (net + *sum) -> ip[0] == 0 && (net + *sum) -> ip[1] == 0 && (net + *sum) -> ip[2] == 0 && (net + *sum) -> ip[3] == 0)
			break;
	}
}
void print(char name[20][20], int same[20], int sum){
	printf("machines ");
	int i;
	for (i = 0; i < sum - 2; i++)
		printf("%s, ", name[same[i]]);
	printf("%s and %s are on the same local network.\n", name[same[i]], name[same[i + 1]]);
}
void find(netdata net[20], int ip0, int ip1, int sum){
	int same[20] = { 0 }, sum_s = 0, i;
	for (i = 0; i<sum; i++) {
		if ((net+i)->ip[0] == ip0 && (net+i)->ip[1] == ip1) {
			same[sum_s++] = i;
			(net+i)->ip[0] = -1;
		}
	}
	if (sum_s >= 2)
		print(net->name, same, sum_s);
}
void output(netdata net[20], int sum){
	int i;
	for (i = 0; i < sum; i++)
		if ((net+i)->ip[0] >= 0)
			find(net, (net+i)->ip[0], (net+i)->ip[1], sum);
	for (i = 0; i < sum; i++)
		if ((net+i)->ip[0] == -2)
			printf("machine %s is error ip\n", net->name[i]);
}
int main(){   //-1 used,-2 error.
	int sum = 0;
	netdata net[20];
	input(net, &sum);
	output(net, sum);
}
