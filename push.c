/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:03:07 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/23 14:31:59 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swapb(t_stack *stack)
{
	int	tmp;

	tmp = stack->stackb[0];
	stack->stackb[0] = stack->stackb[1];
	stack->stackb[1] = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack *stack)
{
	int	tmp;
	int	j;

	j = 0;
	while (j < stack->sizea - 1)
	{
		tmp = stack->stacka[j];
		stack->stacka[j] = stack->stacka[j + 1];
		stack->stacka[j + 1] = tmp;
		j++;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	j;

	j = 0;
	while (j < stack->sizeb - 1)
	{
		tmp = stack->stackb[j];
		stack->stackb[j] = stack->stackb[j + 1];
		stack->stackb[j + 1] = tmp;
		j++;
	}
	write(1, "rb\n", 3);
}

void	pushb(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (stack->sizea == 0)
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
	write(1, "pb\n", 3);
}

void pusha(t_stack *stack)
{
	int i =0;
	int j ;
	int tmp;
	if (stack->sizeb == 0)
		return ;
	stack->sizea++;
	tmp = stack->stackb[0];
	while (i < stack->sizeb)
	{
		stack->stackb[i] = stack->stackb[i + 1];
		i++;
	}
	j = stack->sizea;
	while (j)
	{
		stack->stacka[j] = stack->stacka[j - 1];
		j--;
	}
	stack->stacka[0] = tmp;
	write(1,"pa",1);
	
}