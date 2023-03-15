/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:48:42 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/15 05:12:13 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_smallest(t_stack *stack ,int j)
{
    int i;
    int l;
    int smallest;
    l = 0;
    i = 0;
    smallest = 0;
    while (l < j - 1)
    {
        i = 0;
        
        while (i < j - 1)
        {
            if (stack->stacka[l] < stack->stacka[i + 1] && stack->stacka[l] < smallest) 
                {
                    smallest = stack->stacka[l];
                }
            i++;
        }
        l++;
    }
    return smallest;
}
void ft_sortthree(t_stack *stack ,int i)
{

    if (stack->stacka[0] > stack->stacka[1])
            swapa(stack); 
    if (stack->stacka[0] == i)
        pushb(stack);
    if(ft_ifsorted(stack,stack->sizea))
        return ;
    else
        while (stack->stacka[0] != i)
            ra(stack);
    if (stack->stacka[0] == i)
        pushb(stack);
    if (i == 1)
        return ;
    ft_sortthree(stack,i - 1);
    pusha(stack);
    ra(stack);
}
void my(void)
    {
        
    system("leaks push");
    }
int main(int ac, char **av)
{
    atexit(my);
    t_stack *stack;
    stack = malloc(sizeof(t_stack));
    if (!stack)
        exiterr();
    ft_initstack(av, ac, stack);
    if (stack->args == 3)
        ft_sortthree(stack, 2);
    else if (stack->args == 4)
        ft_sortthree(stack, 3);
    else if (stack->args == 5)
        ft_sortthree(stack, 4);
    else
        radixsorter(stack);
    return 0;
}
