/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:47:43 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/15 13:29:16 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
void rra(int stack)
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