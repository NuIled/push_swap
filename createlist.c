/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:44:46 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/16 21:43:38 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiterr(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

void	checkargs(char *av, int i, t_stack *stack)
{
	while (av[i])
	{
		if (ft_sign(av[i]) && ft_isdigit(av[i + 1]))
			i++;
		if (ft_isdigit(av[i]))
		{
			stack->args++;
			while (ft_isdigit(av[i]))
				i++;
		}
		else if (av[i] == ' ')
			while (av[i] == ' ')
				i++;
		else
			exiterr();
	}
}

void	listcreating(char **av, t_stack *stack, int j)
{
	char	**str;
	char	*tmp;
	char	**s;
	int		l[3];

	l[0] = -1;
	l[1] = 0;
	while (++l[1] < j)
	{
		stack->over = 0;
		str = ft_split(av[l[1]], ' ');
		if (!str)
			exiterr();
		s = str;
		while (*str)
		{
			tmp = *str;
			stack->stacka[++l[0]] = ft_atoi(*str++);
			free(tmp);
		}
		free(s);
	}
}
