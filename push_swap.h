/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:45:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/25 03:05:44 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *h, const char *nl, size_t n);

typedef struct stack{
    int *stacka;
    int *stackb;
    int args;
}t_stack;
void checkargs(char *av , int ac,t_stack *stack);
int listcreating(int i, char *av ,t_stack *stacka);
int chek(char **av, int ac,t_stack *stack);
#endif