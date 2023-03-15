/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:44:46 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/15 05:12:42 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void exiterr(void)
{
	write(2,"\nerror\n",8);
	exit(1);
}
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int ft_sign(int c)
{
	if(c == '+' || c == '-')
		return 1;
	return 0;
}
void checkargs(char *av , int i, t_stack *stack)
{
	while (av[i])
	{
		
		if(ft_sign(av[i]) && ft_isdigit(av[i + 1]))
			i++;
		if(ft_isdigit(av[i]))
		{
			stack->args++;
			while (ft_isdigit(av[i]))
				i++;
		}
		else if(av[i]== ' ')
			while (av[i] == ' ')
				i++;
		else
			exiterr();
	}
}

void listcreating(char **av, t_stack *stack, int j)
{
 	char **str;
	int l;
	int i;
	i =-1;
	l = 0;
	while (++l < j)
	{
		stack->over = 0;
		str = ft_split(av[l], ' ');
		if(!str)
			exiterr();
		while (*str)
			stack->stacka[++i] = ft_atoi(*str++);
	}
}

void checkdub(t_stack *stack, int j)
{
	int i;
    int l;
    l = 0;

    while (l < j)
    {
        i = 1;
        
        while (i + l < j)
        {
            if(stack->stacka[l] == stack->stacka[i + l])
			{
				free(stack);
				exiterr();
			}
			i++;
	 	}
    l++;
    }
}

void ft_initstack(char **av, int ac, t_stack *stack)
{
	int i;

	i = 0;
	stack->args = 0;
	while (++i < ac)
		checkargs(av[i], 0, stack);
	stack->sizea = stack->args;
	stack->sizeb = 0;
	stack->stacka = ft_calloc (1,stack->args * sizeof(int));
	stack->stackb = ft_calloc (1,stack->args * sizeof(int));
	stack->sorted = ft_calloc (1,stack->args * sizeof(int));
	if(!stack->stacka || !stack->stackb || !stack->sorted)
		exiterr();
	listcreating(av, stack, ac);
	checkdub(stack,stack->sizea);
	sorter(stack);
}
