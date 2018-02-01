#include <stdio.h>


void percentage(int *money)
{
	int pa;
	if (money[0] < 0 && money[1] > 0)
		pa = 0;
	else if (money[1] < 0 && money[0] > 0)
		pa = 100;
	else if (money[1] == 0 && money[0] == 0)
		pa = 50;
	else
		pa = *money * 100 / (money[0] + money[1]);
	printf("A:%d%%,B:%d%%\n",pa,100-pa);
}
void ATM()
{
	int acc, money[2] = { 0 }, cost;
	char ins;
	while (1)
	{
		scanf(" %c", &ins);
		if (ins == 'a')
		{
			acc = 0;
			printf("Select A\n");
		}
		else if (ins == 'b')
		{
			acc = 1;
			printf("Select B\n");
		}
		else if (ins == 'v')
		{
			printf("%c:%d\n", 'A' + acc, money[acc]);
		}
		else if (ins == 'w')
		{
			scanf(" %d", &cost);
			printf("%c:Withdraw,%d\n", 'A' + acc, cost);
			money[acc] -= cost;
			printf("%c:%d\n", 'A' + acc, money[acc]);
		}
		else if (ins == 's')
		{
			scanf(" %d", &cost);
			printf("%c:Deposit,%d\n", 'A' + acc, cost);
			money[acc] += cost;
			printf("%c:%d\n", 'A' + acc, money[acc]);
		}
		else if (ins == 'p')
			percentage(money);
		else if (ins == 'e')
			break;
	}
}
int main()
{
	ATM();
    return 0;
}
