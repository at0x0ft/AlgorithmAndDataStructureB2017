#include <stdio.h>
#include <stdlib.h>

const int maxlen = 10000;

int compare(const int *, const int *);
int convertStr2Num(const char[], int *);
int countDistrict(const char[], const int);
int calcLeast(const char[], int *);
int neededVotes(const char[], int *);

int main(void)
{
	int n, stptr, i;
	char buffer[maxlen + 1];

	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		stptr = 0;
		fgets(buffer, maxlen, stdin);				 // 票数を表す文字列を取得する.
		printf("%d\n", neededVotes(buffer, &stptr)); // 必要最小限の票数を計算し, 取得する.
	}

	return 0;
}

int compare(const int *x, const int *y) // qsortで必要な比較関数(x < yなら-1, x == y なら0, x > y を返す).
{
	return *x < *y ? -1 : (*x == *y ? 0 : 1);
}

int convertStr2Num(const char buffer[maxlen + 1], int *stptr) // 文字列の連続した数値の並びを数値に変換し返す関数.
{
	int ans = 0;

	while (buffer[*stptr] != ']')
	{
		ans *= 10;
		ans += buffer[(*stptr)++] - '0';
	}

	return ans / 2 + 1;
}

int countDistrict(const char buffer[maxlen + 1], const int stptr) // 選挙区の数を計算する関数.
{
	int i, pflg = 0, count = 0;

	for (i = stptr; pflg >= 0; i++)
	{
		if (buffer[i] == '[')
		{
			pflg++;
		}
		else if (buffer[i] == ']')
		{
			pflg--;
			if (pflg == 0)
			{
				count++;
			}
		}
	}

	return count;
}

int calcLeast(const char buffer[maxlen + 1], int *stptr) // 選挙区の数を計算し, その中で必要な過半数票数を計算する.
{
	int i, count, needed, *votes, ans = 0;

	count = countDistrict(buffer, *stptr); // 選挙区の数を計算する.

	votes = malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		votes[i] = neededVotes(buffer, stptr); // それぞれの選挙区について, 必要な過半数票数を計算し, votesに格納していく.
	}

	qsort(votes, count, sizeof(int), (int (*)(const void *, const void *))compare); // 票数を昇順に並べ替える.

	needed = count / 2 + 1; // 必要選挙区は, 選挙区数の過半数.

	for (i = 0; i < needed; i++)
	{
		ans += votes[i]; // 必要票数の少ない選挙区から順に答えに加算する.
	}

	free(votes);

	return ans;
}

int neededVotes(const char buffer[maxlen + 1], int *stptr)
{
	int ans;

	(*stptr)++;
	if (buffer[*stptr] >= '0' && buffer[*stptr] <= '9')
	{
		ans = convertStr2Num(buffer, stptr); // "[]"の中に数値が直接入っていれば, その中の数値の過半数を計算する.
	}
	else
	{
		ans = calcLeast(buffer, stptr); // 更に選挙区があればその中で必要な過半数を計算する.
	}

	(*stptr)++;

	return ans;
}