#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
	int been[6];
	int enemy[9];
} team_t;
bool ok(int num) {
	int a = num / 10;
	int b = num % 10;
	if (a >= b) return false;
	if (a > 8 || b > 8) return false;
	if (a*b == 0) return false;
	return true;
}
bool rep(int num1, int num2) {
	int a = num1 / 10, b = num1 % 10, c = num2 / 10, d = num2 % 10;
	if (a == c || a == d || b == c || b == d) return true;
	return false;
}
bool errorTime(int arr[5], int game) {
    int i;
	for (i = 0; i < 5; i++)
		if (arr[i] > 11 && rep(game, arr[i])) return true;
	return false;
}
int getGame(int list[5][5], team_t team[], int round, int game) {
	int result = 12;
	while (result <= 78) {
		int team1 = result / 10;
		int team2 = result % 10;
		if (!ok(result)) result++;
		else if (errorTime(list[round], result)) result++;
		else if (team[team2].been[game] > 0) result++;
		else if (team[team1].been[game] > 0) result++;
		else if (team[team1].enemy[team2] > 2) result++;
		else return result;
	}
	return -1;
}
int main() {
	team_t team[9] = { 0 };
	int list[5][5] = { 0 }, i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j) list[i][j] = 0;
			else {
				list[i][j] = getGame(list, team, i, j);
				team[list[i][j] / 10].enemy[list[i][j] % 10]++;
				team[list[i][j] % 10].enemy[list[i][j] / 10]++;
				team[list[i][j] / 10].been[j]++;
				team[list[i][j] % 10].been[j]++;
			}
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%2d ", list[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",team[8].been[0]);
	system("PAUSE");
}
/*
57 48 23  0 16
68 45 17 23  0
24 36  0 18 57
 0 12 34 56 78
13  0 25 47 68
*/
