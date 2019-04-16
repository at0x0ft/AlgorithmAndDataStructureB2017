void STinit(int);
int STcount(void);
void STinsert(Item);
Item STsearch(Key, int *, int *);
void STdelete(Item);
Item STselect(int);
void STsort(void (*visit)(Item));
