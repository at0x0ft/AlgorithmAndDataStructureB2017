#include <stdio.h>

#define FIRST_YEAR 1896 // 第1回夏季オリンピックは1896年.

int main(void)
{
  int N, Y;

  scanf("%d", &N);

  while (--N >= 0)
  {
    scanf("%d", &Y); // Yを標準入力から受け取る.

    printf("%d\n",
           Y >= FIRST_YEAR && Y % 4 == 0  // 4の倍数かつ1896年以降であれば
               ? (Y - FIRST_YEAR) / 4 + 1 // 夏季オリンピックの回数を示し,
               : -1);                     // そうでなければ-1を表示する.
  }

  return 0;
}
