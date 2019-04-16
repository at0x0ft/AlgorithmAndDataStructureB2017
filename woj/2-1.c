#include <stdio.h>

void judge(int d) // 方角を判定し, 結果を表示する関数.
{
  d /= 45;
  switch (d)
  {
  case 0:
    printf("N\n");
    break;
  case 1:
    printf("NW\n");
    break;
  case 2:
    printf("W\n");
    break;
  case 3:
    printf("SW\n");
    break;
  case 4:
    printf("S\n");
    break;
  case 5:
    printf("SE\n");
    break;
  case 6:
    printf("E\n");
    break;
  case 7:
    printf("NE\n");
    break;
  }
}

int main(void)
{
  int d;

  while (1)
  {
    scanf("%d", &d); // dを受け取る.
    if (d == -1)     // d=-1なら終了.
    {
      break;
    }
    judge(d); // 受け取ったdから方角を判定し, 出力する.
  }

  return 0;
}
