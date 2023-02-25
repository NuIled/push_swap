/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:44:46 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/25 05:08:52 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void exiterr(void)
{
	printf("error");
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

int listcreating(int i, char *av ,t_stack *stack)
{
 	char *s;
	static int j;
	int a;
	int arr[stack->args];
	stack->stacka=arr;
	if(!stack)
		return (0);
	while (av[i])
	{
		if(av[i] == ' ')
			i++;
		if(av[i] == '-' || av[i] == '+' || ft_isdigit(av[i]))
		{
			a = 1;
			i++;
			while (ft_isdigit(av[i]))
			{
				a++;
				i++;
			}
			s =	ft_substr(av, i - a , a);
			arr[j++] = ft_atoi(s);
		}
	}
	free(s);
	return 1;
}

int checkdub(t_stack *stack, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if(!ft_memcmp(&stack->stacka[i], &stack->stacka[i + 1], sizeof(int)))
			exiterr();
		i++;
	}
	return 1;
}

int chek(char **av, int ac, t_stack *stack)
{
	int i;
	i = 1;
	stack->args=0;
	while (i < ac)
		checkargs(av[i++],0,stack);
	i = 1;
	while (i < ac)
	{
		if(!listcreating(0, av[i],stack))
			return 0;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if(!checkdub(stack,stack->args))
			return 0;
		i++;
	}
	
	return 1;
}