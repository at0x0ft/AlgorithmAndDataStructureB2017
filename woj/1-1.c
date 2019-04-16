#include <stdio.h>
#include <stdlib.h>

int min(const int x, const int y) // 引数xとyの最小値を返す関数.
{
	return x > y ? y : x;
}

int main(void)
{
	int N, a[3], i; // データセットの数, 3つの数値, ループ変数.

	scanf("%d", &N); // データセット数の取得.

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d", &a[0], &a[1], &a[2]);											// データセットの入力
		printf("%d\n", min(abs(a[0] - a[1]), min(abs(a[1] - a[2]), abs(a[2] - a[0])))); // 3通りの絶対値のうち最も小さいものを求め、標準出力する。
	}

	return 0;
}