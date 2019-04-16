#include <stdio.h>
#include <stdlib.h>

int sdJudge(const char *L, const int sk, const int dk) // 'S'と'D'がsk番目, sl番目に存在するか確認する関数
{
	return L[sk] == 'S' && L[dk] == 'D';
}

void judgeDown(int *count, const char *L, const int k, const int N) // k番地の'W'の下方向で"WSD"が完成するか
{
	if (k / N <= N - 3 && sdJudge(L, k + N, k + 2 * N))
	{
		(*count)++;
	}
}

void judgeRight(int *count, const char *L, const int k, const int N) // k番地の'W'の右方向で"WSD"が完成するか
{
	if (k % N <= N - 3 && sdJudge(L, k + 1, k + 2))
	{
		(*count)++;
	}
}

void judgeLeft(int *count, const char *L, const int k, const int N) // k番地の'W'の左方向で"WSD"が完成するか
{
	if (k % N >= 2 && sdJudge(L, k - 1, k - 2))
	{
		(*count)++;
	}
}

void judgeUp(int *count, const char *L, const int k, const int N) // k番地の'W'の上方向で"WSD"が完成するか
{
	if (k / N >= 2 && sdJudge(L, k - N, k - 2 * N))
	{
		(*count)++;
	}
}

void judgeWSD(int *count, const char *L, const int k, const int N) // "WSD"が含まれる部分を検出し, その数を第一引数countに入力する関数.
{
	judgeDown(count, L, k, N);
	judgeRight(count, L, k, N);
	judgeLeft(count, L, k, N);
	judgeUp(count, L, k, N);
}

char *inputTable(char *L, const int N) // 文字列ブロックを取得し, その一次元配列文字列へのポインタを返か関数.
{
	int k = 0;
	char buffer;
	L = malloc(sizeof(char) * (N * N + 1));
	while (k < N * N)
	{
		scanf("%c", &buffer);
		if (buffer != '\n') // 改行文字以外であれば文字列に書き込む.
		{
			L[k] = buffer;
			k++;
		}
	}

	L[k] = '\0';
	return L;
}

int wsdCount(void) // 文字列ブロックを取得し, その中に含まれる"WSD"の数を計算して返す関数.
{
	int N, i, count = 0;
	char *L;
	scanf("%d", &N);	  // ブロックの縦横の数を取得する.
	L = inputTable(L, N); // 文字列ブロックを取得する.

	for (i = 0; i < N * N; i++)
	{
		if (L[i] == 'W')
		{
			judgeWSD(&count, L, i, N); // "WSD"が含まれる部分を検出し, その数を第一引数countに入力する関数.
		}
	}

	free(L);
	return count;
}

int main(void)
{
	int D, i;

	scanf("%d", &D); // 文字列ブロックの個数を取得.
	for (i = 0; i < D; i++)
	{
		printf("%d\n", wsdCount()); // 文字列ブロックを取得し, その中に含まれる"WSD"の数を計算し表示する.
	}

	return 0;
}