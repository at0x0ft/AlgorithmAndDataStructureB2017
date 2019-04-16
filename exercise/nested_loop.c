#include <stdio.h>

void nested_loop(int *outer, int size_of_outer, int *inner, int size_of_inner)
{
    int i, j, join_count = 0;

    for (i = 0; i < size_of_outer; i++)
    {
        for (j = 0; j < size_of_outer; i++)
        {
            if (outer[i] == inner[i])
            {
                printf("%d %d\n");
            }
        }
    }
}