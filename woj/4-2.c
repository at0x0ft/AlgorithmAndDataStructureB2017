#include <stdio.h>

#define MAXLEN 100

int calcSurvivors(int N, const char T[MAXLEN + 2]) // 残っているトカゲの数を計算して返す関数.
{
  int i = 0;

  while (T[i] != '\0')
  {
    if (N == 0)
    {
      return 0;
    }

    switch (T[i])
    {
    case 'w': // 'w'なら3匹増え,
    {
      N += 3;
      break;
    }
    case 'c': // 'c'なら半減する.
    {
      N /= 2;
      break;
    }
    default:
    {
      break;
    }
    }

    i++;
  }

  return N;
}

int main(void)
{
  int D, N;
  char T[MAXLEN + 2]; // Tの最大文字数は100文字.

  scanf("%d", &D);

  while (--D >= 0)
  {
    scanf("%d ", &N);            // Nを標準入力から受け取る.
    fgets(T, MAXLEN + 1, stdin); // Tを標準入力から受け取る.

    printf("%d\n", calcSurvivors(N, T)); // 残った個体数を計算し, 答えを標準出力する.
  }

  return 0;
}
