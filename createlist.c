/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:44:46 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/05 09:29:03 by aoutifra         ###   ########.fr       */
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

int listcreating(int i, char **av ,t_stack *stack,int j)
{
	// int n = 0;
	
 	char *s;
 	char *avv;
	int a;
	int l = 1;
	while (l < j)
	{
		i = 0;
		avv =	ft_substr(av[l], 0 , ft_strlen(av[l]));

		while (avv[i] && stack->sizeb >= 0)
		{
		while(avv[i] == ' ')
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
				stack->stacka[--stack->sizeb] = ft_atoi(s);
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
	stack->sizea = stack->args;
	stack->sizeb = stack->args;
    stack->longe  = 0;
	stack->stacka = malloc(((stack->args) * sizeof(int)));
	stack->stackb = malloc((stack->args * sizeof(int)));
	if(!stack->stacka || !stack->stackb)
		return (0);
	if(!listcreating(0, av, stack, ac))
			exit (0);
	checkdub(stack,stack->sizea);
	while(!ft_ifsorted(stack)) 
		pushalltob(stack);
	printf("\ninstract %i\n",stack->longe);
	for (int i = 0; i < ac; i++)
		printf("\na0rgs = %d", stack->stacka[i]);
	printf("\nac==%i\n",ac);
	return 1;
}
