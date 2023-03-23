/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/23 14:19:42 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_stack *stack)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (i < stack->sizea)
	{
		m = 0;
		j = 0;
		while (m < stack->sizea)
		{
			if (stack->stacka[i] > stack->stacka[m])
				j++;
			m++;
		}
		stack->sorted[i] = j;
		i++;
	}
	i = -1;
	while (++i < stack->sizea)
		stack->stacka[i] = stack->sorted[i];
}

void	sorthree(t_stack *stack)
{
	if (stack->stacka[0] == 0)
	{
		if (stack->stacka[1] == 2)
			swapa(stack);
		ra(stack);
	}
	if (stack->stacka[0] == 2)
	{
		if (stack->stacka[1] == 0)
			ra(stack);
		else
			swapa(stack);
	}
	if (stack->stacka[0] == 1)
	{
		if (stack->stacka[1] == 0)
			swapa(stack);
		else
		{
			ra(stack);
			ra(stack);
		}
	}
}
