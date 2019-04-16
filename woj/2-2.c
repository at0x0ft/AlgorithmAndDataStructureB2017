#include <stdio.h>
#include <stdlib.h>

void inputT(int N, int T[100]) // Tを入力する関数.
{
  int i;
  for (i = 0; i < N; i++)
  {
    scanf("%d", &T[i]);
  }
}

int compare(const int *x, const int *y) // qsortで必要な比較関数(x < yなら-1, x == y なら0, x > y を返す).
{
  return *x < *y ? -1 : (*x == *y ? 0 : 1);
}

void calcMin(int N, int T[100])
{
  qsort(T, N, sizeof(int), (int (*)(const void *, const void *))compare); // 温度を昇順に並べ替える.
  printf("%d\n", T[N - 1] - T[0]);                                        // 結果の表示(温度差の絶対値の合計はソート後のT配列の最大値-最小値).
}

int main(void)
{
  int N, T[100]; // Nの最大値は100なので, T配列の要素数は100個としておく.

  while (1)
  {
    scanf("%d", &N); // Nを受け取る.
    if (N == 0)      // N = 0なら終了.
    {
      break;
    }
    inputT(N, T);  // T配列に温度を入力.
    calcMin(N, T); // 最小の温度差を計算し, 出力する.
  }

  return 0;
}
