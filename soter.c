/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/27 04:22:15 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_ifsorted(t_stack *stack)
{
    int i;
    i = 0;

    while (i < stack->args)
    {
        if(ft_memcmp(&stack->stacka[i],&stack->stacka[i + 1],sizeof(int)) == -1)
            return 0;
        i++;
    }
    return 1;
}

int smallest(t_stack *stack ,int j)
{
    int i;
    
    i = 0;
    while (i < j)
    {
        if(ft_memcmp(&stack->stacka[i],&stack->stacka[i + 1],sizeof(int)) == -1)
            stack->pos = stack->stacka[i + 1];
        i++;
    }
    return stack->pos;
}

void swapb(t_stack *stack)
{
    int tmp;
    tmp = stack->stackb[0];
    stack->stackb[0] = stack->stackb[1];
    stack->stackb[1] = tmp;
}

void rrb(t_stack *stack ,int j)
{
    int i = 0;
    int tmp;

    tmp = stack->stacka[j - 1];
        // printf("\nstack->stacka== %i ===\n", stack->stacka[6]);
    while(--j >= 0)
       { 
        stack->stacka[j] = stack->stacka[j - 1];
        i++;
        }
    stack->stacka[0] = tmp;
}
void pushalltob(t_stack *stack)
{
    int i;
    int j;
    j = 0;
    i = 0;
    while (!ft_ifsorted(stack))
    {
        smallest(stack,(stack->args - 1 - i));
		printf("\n--after-%i++++\n",stack->pos);
        while (stack->stacka[0]!= stack->pos)
            rrb(stack,stack->args);
        pushb(stack);
        // for(int i = 0 ; i < stack->args-1; i++)
        // printf("\nstack->pos b[0]== %i ===\n", stack->pos);
        i++;
        if (i == stack->args)
            {
                while (j++ < stack->args)
                    pusha(stack);
                break;
            }
    }
}
int sortb(t_stack *stack)
{
    int i;
    int j;
    int l;
    j = 0;
    i = 0;
    l = 0;
    while (i < 6)
    {
        i = 0;
        if(-1 == ft_memcmp(&stack->stackb[i],&stack->stackb[i + 1],sizeof(int)))
            i++;
        if(stack->stackb[0] < stack->stackb[1])
            swapb(stack);
        if(-1 == ft_memcmp(&stack->stackb[i],&stack->stackb[i + 1],sizeof(int)))
            while(j++ < i)
                pusha(stack);
        while (l < i - j)
        {
            rrb(stack, i - j);
            if(stack->stackb[0] < stack->stackb[1])
                swapb(stack);
            l++;
        }
        if(i == 6)
            break;
    }
    return 1;
}

int pushb(t_stack *stack)
{
    int i;  
    static int k;
    int tmp;
    int j;
    i = 0;
    j = 0;
    
        tmp = stack->stacka[i];
    while (i < stack->args)
    {
        while (j < stack->args-1)
        {
            stack->stacka[j] = stack->stacka[j + 1];
            j++;
        }
        // for(int i = 0 ; i < stack->args; i++)
		//     printf("\n--bigo-%i++++\n",stack->stacka[i]);
        while (i < k)
        {
            stack->stackb[i + 1] = stack->stackb[i];
            i++;
        }
        stack->stackb[0] = tmp;
        k++;
        // printf("\nstack b[0]== %i ===\n",stack->stacka[0]);
    }
    return 0;
}
int pusha(t_stack *stack)
{
     int i;
    int tmp;
    static int j;
    i = 0;
    j = 0;
    
    while (i < stack->args)
    {
        tmp = stack->stackb[i];
        while (i < stack->args)
        {
            stack->stackb[i] = stack->stackb[i + 1];
            i++;
        }
        while (j < stack->args)
        {
            if (j == 0)
            {
                stack->stacka[j] = tmp;
                return 1;
            }
            stack->stacka[j + 1] = stack->stacka[j];
            j++;
        }
        stack->stacka[0] = tmp;   
    }
    return 0;
}