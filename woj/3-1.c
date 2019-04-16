#include <stdio.h>

const int maxlen = 30; // 出力する数値の文字数は最大でも30文字を超えない.

void convert(const int B, int *T, int *anslen, char ans[maxlen + 1])
{
  *anslen = 0;
  do
  {
    *T % B > 9                                     // T % Bを計算し,
        ? (ans[(*anslen)++] = *T % B + ('A' - 10)) // 9よりも大きいようであれば文字を代入し,
        : (ans[(*anslen)++] = *T % B + ('0' - 0)); // 9以下であればそのまま数値を代入する.
    *T /= B;                                       // 次の位の数の計算に移るため, TをBで割っておく
  } while (*T > 0);
}

void printAns(int *anslen, char ans[maxlen + 1]) // 答えを出力する関数.
{
  while (--(*anslen) >= 0)
  {
    printf("%c", ans[*anslen]);
  }
  printf("\n");
}

int main(void)
{
  int N, B, T, anslen, i; // anslenに答えの数値の桁数を格納しておく.
  char ans[maxlen + 1];   // 答えを文字列として格納しておく.

  scanf("%d", &N); // Nを標準入力から受け取る.

  for (i = 0; i < N; i++)
  {
    scanf("%d %d", &B, &T);       // B, Tを標準入力から受け取る.
    convert(B, &T, &anslen, ans); // TをB進数に変換し, その答えをansに格納する.

    printAns(&anslen, ans); // 答えを出力する.
  }

  return 0;
}
