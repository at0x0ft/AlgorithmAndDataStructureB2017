#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

#define MAX 56
#define TRIAL 30

int main(int argc, char **argv)
{
  int succeededSearchCount = 0;
  int failedSearchCount = 0;
  Item u, v;
  STinit(MAX);

  int cnt;
  for (cnt = 0; cnt < atoi(argv[1]) && cnt < 2 * MAX;)
  {
    int k = rand();
    key(u) = k;
    v = STsearch(k, &succeededSearchCount, &failedSearchCount);

    if (key(v) != key(NULLitem))
    {
      printf("Key %d is found in the table.\n", k);
    }
    else
    {
      cnt++;
      STinsert(u);
      printf("Key %d is not found in the table.\n", k);
    }
  }

  printf("AveSucceededCount:%f\n", 1.0 * succeededSearchCount / atoi(argv[1]));
  printf("AveFailedCount:%f\n", 1.0 * failedSearchCount / atoi(argv[1]));

  return 0;
}