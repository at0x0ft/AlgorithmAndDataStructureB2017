#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
  int i;

  if ((n == 2 || n == 3) || n == 5)
  {
    return 1;
  }
  else if ((n == 1 || n % 2 == 0) || (n % 3 == 0 || n % 5 == 0))
  {
    return 0;
  }

  for (i = 1; (6 * i + 1) <= sqrt(n); i++)
  {
    if (n % (6 * i + 1) == 0)
    {
      return 0;
    }
  }

  for (i = 1; (6 * i + 5) <= sqrt(n); i++)
  {
    if (n % (6 * i + 5) == 0)
    {
      return 0;
    }
  }

  return 1;
}

int main(void)
{
  int N, i;

  while (1)
  {
    scanf("%d", &N);
    if (N == 0)
    {
      break;
    }

    for (i = 2; i <= sqrt(N); i++)
    {
      if (N % i == 0 && isPrime(i) && isPrime(N / i))
      {
        printf("YES\n");
        break;
      }
    }

    if (i > sqrt(N))
    {
      printf("NO\n");
    }
  }

  return 0;
}
