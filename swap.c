/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:24:01 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/21 23:02:43 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	maxbits(t_stack *stack)
{
	int	size;

	stack->maxbit = 0;
	size = stack->sizea - 1;
	while (size > 1)
	{
		stack->maxbit++;
		size /= 2;
	}
}

void	radixsorta(t_stack *stack, int i)
{
	int	j;
	int	size;

	j = 0;
	size = stack->sizea;
	while (j < size && !ft_ifsorted(stack, stack->sizea - 1))
	{
		if (((stack->stacka[0] >> i) & 1) == 0)
			pushb(stack);
		else
			ra(stack);
		j++;
	}
}

void	radixsortb(t_stack *stack, int i)
{
	int	j;
	int	size;

	j = 0;
	size = stack->sizeb;
	while (j < size)
	{
		if (((stack->stackb[0] >> i) & 1) == 0)
			rb(stack);
		else
			pusha(stack);
		j++;
	}
}

void	radixsorter(t_stack *stack)
{
	int	i;

	i = 0;
	maxbits(stack);
	while (i <= stack->maxbit)
	{
		radixsorta(stack, i);
		i++;
		radixsortb(stack, i);
	}
	while (stack->sizeb)
		pusha(stack);
	free(stack->stackb);
	free(stack);
}

void	swapa(t_stack *stack)
{
	int	tmp;

	tmp = stack->stacka[0];
	stack->stacka[0] = stack->stacka[1];
	stack->stacka[1] = tmp;
	write(1, "sa\n", 3);
}
