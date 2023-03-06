#include "push_swap.h"
int ft_ifsorted(t_stack *stack)
{
    int i;
    i = 0;


    while (i < 5)
    {
		printf("\nstacko = %d\n", stack->stacka[i]); 
        if(stack->stacka[i] > stack->stacka[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char *av[])
{
    // int i  = 0;
    t_stack *stack;
    int j[] = {1,6,8,9,1,0,25,35,65,31};
    stack = malloc(sizeof(t_stack));
    stack->stacka = j;
    ft_ifsorted(stack);
    // chek(av,ac,stack);

    // while (sizeof(stack->stacka[i]) == sizeof(int))
    //     {
    //         i++;
    //         j++;
    //     }
    // printf("\n%i\n",j);
}
