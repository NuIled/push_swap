/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:01 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ./push_swap 5 6 3 15 -1-1
int ft_ifsorted(t_stack *stack)
{
    int i;
    i = 0;


    while (i <= stack->args)
    {
        if(stack->stacka[i] > stack->stacka[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int smallest(t_stack *stack ,int j)
{
    int i;
    int l;
    stack->pos = stack->stacka[0];
    l = 0;
    i = 0;

    while (l < j - 1)
    {
        i = 0;
        
        while (i < j - 1)
        {
            if (stack->stacka[l] < stack->stacka[i + 1] && stack->stacka[l] < stack->pos) 
                {
                    stack->pos = stack->stacka[l];
                    stack->position = l;

                }
            i++;
        }
        l++;
    }
    return stack->pos;
}

void swapa(t_stack *stack)
{
    int tmp;
    tmp = stack->stacka[0];
    stack->stacka[0] = stack->stacka[1];
    stack->stacka[1] = tmp;
        stack->longe+=1;
    write(1,"sa\n",4);
}
void swapb(t_stack *stack)
{
    int tmp;
    tmp = stack->stackb[0];
    stack->stackb[0] = stack->stackb[1];
    stack->stackb[1] = tmp;
        stack->longe+=1;
    write(1,"sa\n",4);
}

void ra(t_stack *stack ,int j)
{
    int tmp;

    tmp = stack->stacka[j - 1];
    while(j >= 0)
    {
        stack->stacka[j] = stack->stacka[j - 1];
        j--;
    }
    stack->stacka[0] = tmp;
    stack->longe+=1;
    write(1,"\nra\n",4);
}
void rra(t_stack *stack ,int j)
{
    int tmp;
    int i = 0;

    tmp = stack->stacka[0];
	// for (int i = 0; i < 10; i++)
    while(i < j)
    {  
        stack->stacka[i] = stack->stacka[i + 1];
        i++;
    }
    stack->stacka[j - 1] = tmp;
    stack->longe+=1;
    write(1,"\nra\n",4);

   // free(newstack);
}

void pushalltob(t_stack *stack)
{
    int i;
    int j;
    int m;
    i = 0;
    j = 0;
    
    while (!ft_ifsorted(stack))
    {
        j = (stack->args / 2);
        smallest(stack,(stack->args));
        if(stack->stacka[0] > stack->stacka[1])
            swapa(stack);
        if (ft_ifsorted(stack))
            return ;
        while (i < stack->args)
        {
            if (i < j)
                while (stack->stacka[j] < stack->stacka[i] && stack->stacka[0] != stack->stacka[i])
                    rra(stack,(stack->args));
            else
                while (stack->stacka[j] < stack->stacka[i] && stack->stacka[0] != stack->stacka[i])
                    ra(stack,(stack->args));
            pushb(stack,i);
            i++;
        }
        if (ft_ifsorted(stack))
            break;
        else
            while (stack->stacka[0]!= stack->pos)
                rra(stack,(stack->args));
        if(stack->stacka[0] > stack->stacka[1])
            swapa(stack);
        if (ft_ifsorted(stack))
            break;
        pushb(stack,i);
        i++;
        if (ft_ifsorted(stack))
            break;
    }
    if(stack->stackb[0])
        pusha(stack,i);
}


void pushb(t_stack *stack,int j)
{
    int i = 0;
    int tmp;
    tmp = stack->stacka[0];
    while (i < stack->args - 1)
    {
        stack->stacka[i] = stack->stacka[i + 1];
        i++;
    }

    while (j > 0)
    {
        stack->stackb[j] = stack->stackb[j - 1];
        j--;
    }
    stack->stackb[0] = tmp;
    stack->args-=1;
        stack->longe+=1;
        m++;
        write(1,"\npb\n",4);

}

int pusha(t_stack *stack,int i)
{
    int j;
    j = 0;
    int *newstack;
    int m = i;
        

    newstack = malloc(stack->sizea * sizeof(int));
    if (!newstack)
        return (0);
        
        while (-1 != stack->args)
            newstack[--stack->sizea]= stack->stacka[--stack->args];
        while (j < m)
        {
            newstack[i - 1] = stack->stackb[j];

            j++;
            i--;
        write(1,"\npa\n",4);
        stack->longe+=1;
        }
        stack->stacka = newstack;

      //  free(newstack);
    
    return 0;
}