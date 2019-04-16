#include <stdio.h>

#define MAXLEN 500

int main(void)
{
  int L, i, index = 0;
  char S[MAXLEN + 1];

  while (1)
  {
    scanf("%d", &L);
    if (L == 0)
    {
      break;
    }

    scanf("%s", S);
    index = 0;
    for (i = 0; i < L; i++)
    {
      switch (S[i])
      {
      case '+':
      {
        ++index;
        index = (index + 26) % 26;
        break;
      }
      case '-':
      {
        --index;
        index = (index + 26) % 26;
        break;
      }
      case '.':
      {
        printf("%c", 'a' + index);
        break;
      }
      }
    }

    printf("\n");
  }

  return 0;
}
