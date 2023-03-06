/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:45:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/05 08:49:22 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *h, const char *nl, size_t n);
void exiterr(void);
typedef struct stack{
    int *stacka;
    int *stackb;
    int args;
    int pos;
    int position;
    int longe;
    int sizea;
    int sizeb;
}t_stack;
void checkargs(char *av , int ac,t_stack *stack);
int listcreating(int i, char **av ,t_stack *stacka, int j);
int chek(char **av, int ac,t_stack *stack);
int smallest(t_stack *stack, int i);
int pusha(t_stack *stack,int i);
void rrb(t_stack *stack ,int j);
void rra(t_stack *stack ,int j);
int sortb(t_stack *stack);
int ft_ifsorted(t_stack *stack);
void pushb(t_stack *stack,int j);
void pushalltob(t_stack *stack);


#endif