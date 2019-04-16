#include <stdio.h>
#include <math.h>

int location(int n, int *l)
{
  int s = sqrt(n + 1);
  if (s % 2 == 0)
  {
    s++;
  }
  *l = s;

  if (n <= s * s - 3 * s + 3)
  {
    return 0;
  }
  else if (n <= s * s - 2 * s + 2)
  {
    return 1;
  }
  else if (n <= s * s - s + 1)
  {
    return 2;
  }

  return 3;
}

int isPrime(int n)
{
  int i;

  if (n == 2 || n == 3 || n == 5)
  {
    return 1;
  }
  else if (n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
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
int bright(int m, int n, int location, int l)
{
  int ans;

  switch (location)
  {
  case 0:
  {
    ans = n - (l - 2) * (l - 2);
    ans += l * l + 1;
    break;
  }
  case 1:
  {
      ans = n - (l - 
      break;
  }
  case 2:
  {
    break;
  }
  case 3:
  {
    break;
  }
  }

  int calcMax(int m, int n, int location, int l, int *fnum)
  {
    int ans = 0;
  }

  int main(void)
  {
    int m, n, l, i;

    while (1)
    {
      scanf("%d %d", &m, &n);
      if (m == 0 && n == 0)
      {
        break;
      }

      fnum = n;
      for (i = 2; i <= sqrt(N); i++)
      {
        if (N % i == 0 && isPrime(i) && isPrime(N / i))
        {
          printf("YES\n");
          break;
        }
      }

      printf("%d %d\n", calcMax(m, n, location(n & l), l, &fnum), fnum);
    }

    return 0;
  }
