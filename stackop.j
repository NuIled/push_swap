# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stackop.j                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 08:47:43 by aoutifra          #+#    #+#              #
#    Updated: 2023/02/26 10:51:01 by aoutifra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#include "stack.h"

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void sa(int *stack)
{
    int i;
    i = 0;
    swap(&stack[i],&stack[i + 1]);
}
void sb(int *stack)
{
    int i;
    i = 0;
    swap(&stack[i],&stack[i + 1]);
}
void rra(int *stack)
{
    int i = 0;
    int tmp;

    while(stack[i])
        i++;
    tmp = stack[--i];
    i = 0;
    while(stack[i])
        stack[++i] = stack[i + 1];
}
void rrb(int *stack)
{
    int i = 0;
    int tmp;

    while(stack[i])
        i++;
    tmp = stack[--i];
    i = 0;
    while(stack[i])
        stack[++i] = stack[i + 1];
}
void shifting(int *stack)
{
    int i = 0;
    int tmp;
    tmp = stack[i];

    while(stack[i])
    {
        stack[i] = stack[i + 1];
        if (i + 1)
            i++;
    }
    stack[--i] = tmp;
}
void rra(int *stack)
{
    int i = 0;
    int tmp;

    while(stack[i])
        i++;
    tmp = stack[--i];
    while(i != 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = tmp;
}
void pa(int *stacka , int *stackb)
{
    int tmp;
    int i = 0;
    tmp = stacka[0];

    while(i <= (sizeof(stackb)/4))
        i++;
    while(i != 0)
    {
        stackb[i] = stackb[i - 1];
        i--;
    }
    stackb[0] = tmp;
}
void pa(int *stacka , int *stackb)
{
    int tmp;
    int i = 0;
    tmp = stackb[0];

    while(i <= (sizeof(stacka)/4))
        i++;
    while(i != 0)
    {
        stacka[i] = stacka[i - 1];
        i--;
    }
    stacka[0] = tmp;
}