#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

Item NULLitem = {0, "NULL"};

Key ITEMrand(void)
{
  return rand() % 100000 + 1;
}

int ITEMscan(Key *x)
{
  return scanf("%d", x);
}

void ITEMshow(Item x)
{
  printf("%3d ", key(x));
}
