/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:48:42 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/21 22:58:17 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkdub(t_stack *stack, int j)
{
	int	i;
	int	l;

	l = 0;
	while (l < j)
	{
		i = 1;
		while (i + l < j)
		{
			if (stack->stacka[l] == stack->stacka[i + l])
				exiterr ();
			i++;
		}
	l++;
	}
}

void	ft_initstack(char **av, int ac, t_stack *stack)
{
	int	i;

	i = 0;
	stack->args = 0;
	while (++i < ac)
		checkargs(av[i], 0, stack);
	stack->sizea = stack->args;
	stack->sizeb = 0;
	stack->stacka = ft_calloc (1, stack->args * sizeof(int));
	stack->stackb = ft_calloc (1, stack->args * sizeof(int));
	stack->sorted = ft_calloc (1, stack->args * sizeof(int));
	if (!stack->stacka || !stack->stackb || !stack->sorted)
		exiterr ();
	listcreating(av, stack, ac);
	checkdub(stack, stack->sizea);
	sorter(stack);
}

int	ft_ifsorted(t_stack *stack, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (stack->stacka[i] > stack->stacka[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_underthre(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 2)
		return (sorthree(stack));
	while (!ft_ifsorted(stack, i))
	{
		while (stack->stacka[0] != j)
			ra(stack);
		pushb(stack);
		--i;
		++j;
		if (i == 2)
		{
			sorter(stack);
			sorthree(stack);
			break ;
		}
	}
	while (j)
	{	
		pusha(stack);
		j--;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = malloc(sizeof(t_stack));
		if (!stack)
			exit(0);
		ft_initstack(av, ac, stack);
		if (ft_ifsorted(stack, stack->args - 1))
			exit(0);
		if (stack->args < 7)
			ft_underthre(stack, stack->args - 1);
		else
			radixsorter(stack);
		free(stack->sorted);
		free(stack->stacka);
	}
	else
		exit(0);
	return (0);
}
