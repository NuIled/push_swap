#include"stdio.h"
#include <string.h>

void paba(int *stacka , int *stackb)
{
    int tmp;
    int i = 0;
    tmp = stacka[0];

    while(stackb[i])
        i++;
    printf("\n%lu\n",sizeof(stackb));
    while(i != 0)
    {
        stackb[i] = stackb[i - 1];
        i--;
    }
    stackb[0] = tmp;
}

int main()
{
    int i = 0;
    int stacka[] = {1,6,1,6,2,8,5};
    int stackb[] = {5,5};
    paba(stacka,stackb);
    while (stackb[i])
        printf("%i",stackb[i++]);
    return 0;
}
