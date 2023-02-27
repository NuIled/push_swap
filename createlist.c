/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:44:46 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/27 03:45:03 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void exiterr(void)
{
	write(1,"\nerror\n",9);
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

int listcreating(int i, char **av ,t_stack *stack,int j)
{
	int l = 1;
 	char *s;
 	char *avv;
	int a;
	while (l < stack->args+1)
	{
		i = 0;
		avv =	ft_substr(av[l], 0 , ft_strlen(av[l]));
	while (avv[i])
	{
		if(avv[i] == ' ')
			i++;
		if(avv[i] == '-' || avv[i] == '+' || ft_isdigit(avv[i]))
		{
			a = 1;
			i++;
			while (ft_isdigit(avv[i]))
			{
				a++;
				i++;
			}
			s =	ft_substr(avv, i - a , a);
			stack->stacka[--j] = ft_atoi(s);
		}
	}
	l++;
	}
	// free(s);
	return 1;
}

int checkdub(t_stack *stack, int j)
{
	int i;
	i = 0;
	// for (size_t f = 0; f < 9; f++)
	while (i + 1 < j)
	{
		if(!ft_memcmp(&stack->stacka[i], &stack->stacka[i + 1], sizeof(int)))
			{
				free(stack);
				exiterr();
			}
		i++;
	}
	return 1;
}

int chek(char **av, int ac, t_stack *stack)
{
	int i;
	static int j;
	i = 1;
	stack->args=0;
	while (i < ac)
		checkargs(av[i++],0,stack);
	i = 1;
	j = stack->args;
	stack->stacka = malloc(((stack->args) * sizeof(int)));
	stack->stackb = malloc((stack->args * sizeof(int)));
	if(!stack->stacka)
		return (0);
	if(!listcreating(0, av, stack, j))
			return 0;

	// stack->last = stack->stacka[stack->args];
	checkdub(stack,j);
	smallest(stack,stack->args);
	pushalltob(stack);
	for(int i = 0 ; i < stack->args; i++)
		printf("\n---%i++++\n",stack->stacka[i]);
	exit(1);
	// printf("\n---%i++++\n",j);
	
	return 1;
}