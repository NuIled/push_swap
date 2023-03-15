/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/15 04:35:34 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_ifsorted(t_stack *stack,int j)
{
    int i;
    i = 0;


    while (i < j)
    {
        if(stack->stacka[i] > stack->stacka[i + 1])
            return 0;
        ++i;
    }
    return 1;
}

void sorter(t_stack *stack)
{
    int i;
    int j;
    int m;

    i = 0;
    m = 0;
    while (i < stack->args)
    {
        m = 0;
        j = 0;
        while (m < stack->args)
        {
            if(stack->stacka[i] > stack->stacka[m])
                j++;
            m++;
        }
        stack->sorted[i] = j;
        i++;
    }
    i = -1;
    while (++i < stack->args)
        stack->stacka[i] = stack->sorted[i];
    free(stack->sorted);
}

void maxbits(t_stack *stack)
{
    stack->maxbit = 0;
    int size;
    size = stack->sizea - 1;
    while (size > 1)
    {
        stack->maxbit++;
        size /= 2;
    }
}
void radixsorta(t_stack *stack , int i)
{
    int j;

    j = 0;
    int size = stack->sizea;
    while(j < size && !ft_ifsorted(stack, stack->sizea))
    {
        if(((stack->stacka[0] >> i) & 1) == 0)
            pushb(stack);
        else
            ra(stack);
        j++;
    }
}
void radixsortb(t_stack *stack , int i)
{
    int j;

    j = 0;
    int size = stack->sizeb;
    
    while(j < size)
    {
        if(((stack->stackb[0] >> i) & 1) == 0)
            rb(stack);
        else
            pusha(stack);
        j++;
    }
}

void radixsorter(t_stack *stack)
{
    int i;
    i = 0; 
    maxbits(stack);
    while (i <= stack->maxbit)
    {
        radixsorta(stack, i);
        i++;
        radixsortb(stack,i);
    }
    while(stack->sizeb)
        pusha(stack);
    free(stack->stackb);
}

void swapa(t_stack *stack)
{
    int tmp;
    tmp = stack->stacka[0];
    stack->stacka[0] = stack->stacka[1];
    stack->stacka[1] = tmp;
        
    write(1,"\nsa",3);
}

void swapb(t_stack *stack)
{
    int tmp;
    tmp = stack->stackb[0];
    stack->stackb[0] = stack->stackb[1];
    stack->stackb[1] = tmp;
        
    write(1,"\nsa",3);
}

void ra(t_stack *stack)
{
    int tmp;
    int j;

    j = 0;
    while (j < stack->sizea - 1)
    {
        tmp = stack->stacka[j];
        stack->stacka[j] = stack->stacka[j + 1];
        stack->stacka[j + 1] = tmp;
        j++;
    }
    write(1,"\nra",3);
}
void rb(t_stack *stack)
{
    int tmp;
    int j;
    
    j = 0;
    while(j < stack->sizeb - 1)
    {
        tmp = stack->stackb[j];
        stack->stackb[j] = stack->stackb[j + 1];
        stack->stackb[j + 1] = tmp;
        j++;
    }
    write(1,"\nrb",3);
}

void pushb(t_stack *stack)
{
    int i;
    int j;
    int tmp;
    
    i = 0;
    if(stack->sizea == 0)
        return ;
    stack->sizeb++;
    tmp = stack->stacka[0];
    while (i < stack->sizea - 1)
    {
        stack->stacka[i] = stack->stacka[i + 1];
        i++;
    }
    j = stack->sizeb;
    while (j > 0)
    {
        stack->stackb[j] = stack->stackb[j - 1];
        j--;
    }
    stack->sizea--;
    stack->stackb[0] = tmp;
        write(1,"\npb",3);
}

void pusha(t_stack *stack)
{
    int i;
    int j;
    int tmp;
    i = 0;
    if(stack->sizeb == 0)
        return ;
    stack->sizea++;
    tmp = stack->stackb[0];
    while (i < stack->sizeb)
    {
        stack->stackb[i] = stack->stackb[i + 1];
        i++;
    }
    j = stack->sizea - 1;
    while (j > 0)
    {
        stack->stacka[j] = stack->stacka[j - 1];
        j--;
    }
    stack->stacka[0] = tmp;
    stack->sizeb--;
        write(1,"\npa",3);
}
