#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
typedef struct STnode *link;
struct STnode
{
  Item item;
  link l, r;
  int N;
};
static link head, z;
link NEW(Item item, link l, link r, int N)
{
  link x = malloc(sizeof *x);
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;
  return x;
}
void STinit()
{
  head = (z = NEW(NULLitem, 0, 0, 0));
}
int STcount(void) { return head->N; }
Item searchR(link h, Key v)
{
  Key t = key(h->item);
  if (h == z)
    return NULLitem;
  if
    eq(v, t) return h->item;
  if
    less(v, t) return searchR(h->l, v);
  else
    return searchR(h->r, v);
}
Item STsearch(Key v)
{
  return searchR(head, v);
}
link insertR(link h, Item item)
{
  Key v = key(item), t = key(h->item);
  if (h == z)
    return NEW(item, z, z, 1);
  if
    less(v, t)
        h->l = insertR(h->l, item);
  else
    h->r = insertR(h->r, item);
  (h->N)++;
  return h;
}

void STinsert(Item item)
{
  head = insertR(head, item);
}
void sortR(link h, void (*visit)(Item))
{
  if (h == z)
    return;
  sortR(h->l, visit);
  visit(h->item);
  sortR(h->r, visit);
}
void STsort(void (*visit)(Item))
{
  sortR(head, visit);
}
int CountStheight(link h)
{
  int lp = 0, rp = 0;
  if (h->l == z && h->r == z)
  {
    return 0;
  }
  if (h->l != z)
  {
    lp = CountStheight(h->l) + 1;
  }
  if (h->r != z)
  {
    rp = CountStheight(h->r) + 1;
  }
  return lp > rp ? lp : rp;
}
int CountStipathlength(int N)
{
  int k = 1, sum = 0;
  if (N == 0 || N == 1)
  {
    return N;
  }
  for (k = 1; k <= N; k++)
  {
    sum += CountStipathlength(k - 1) + CountStipathlength(N - k);
  }

  return (N - 1 + sum / N);
}
void StParameter(int maxN)
{
  printf("N:%d, L:%d, R:%d\n", head->N, head->l->N, head->r->N); // 4debug
  int sthIPathL = CountStipathlength(maxN);
  printf("Stheight:%d\n", CountStheight(head));
  printf("Sthipathlength:%d\n", sthIPathL);
  printf("Stepathlength:%d\n", sthIPathL + (maxN / 2) * 2);
}
