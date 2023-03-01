/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/01 06:10:38 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ./push_swap 5 6 3 15 -1-1
int ft_ifsorted(t_stack *stack)
{
    int i;
    i = 0;


    while (i < stack->args - 1)
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
                    stack->pos = stack->stacka[l];
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
}

void rrb(t_stack *stack ,int j)
{
    int tmp;

    tmp = stack->stacka[j - 1];
    while(j-- >= 0)
        stack->stacka[j] = stack->stacka[j - 1];
    stack->stacka[0] = tmp;
   // free(newstack);
}

void pushalltob(t_stack *stack)
{
    int i;
    int j;
    j = 0;
    i = 0;

    while (!ft_ifsorted(stack))
    {
        smallest(stack,(stack->args));
	   printf("\n%i\n",stack->pos);
        while (stack->stacka[0]!= stack->pos)
            rrb(stack,(stack->args));
        if (ft_ifsorted(stack))
            break;
        pushb(stack,i);
        if(stack->stacka[0] > stack->stacka[1])
            swapa(stack);
        i++;
        
    }
	//    printf("\nargs%i",i);
    	
            pusha(stack,i);
     
}


void pushb(t_stack *stack,int j)
{
    int i = 0;
    int tmp;
    tmp = stack->stacka[0];

    // int *newstack = malloc((stack->args)* sizeof(int));
	//    printf("\narg----s%i",stack->stacka[0]);
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
	//    printf("\narg----s%i",stack->stackb[1]);
    // free(stack->stacka);
    // stack->stacka = newstack;
    stack->args-=1;
}

int pusha(t_stack *stack,int i)
{
    int j;
    j = 0;
    int *newstack;
    int m = i;
        

    newstack = malloc(stack->sizea * sizeof(int));
        
        while (-1 != stack->args)
            newstack[--stack->sizea]= stack->stacka[--stack->args];
        while (j < m)
        {
            newstack[i - 1] = stack->stackb[j];

            j++;
            i--;
        }
        stack->stacka = newstack;

  
      //  free(newstack);
    
    return 0;
}