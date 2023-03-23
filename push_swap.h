/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:45:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/17 02:32:07 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack{
	int	*stacka;
	int	*stackb;
	int	*sorted;
	int	args;
	int	maxbit;
	int	sizea;
	int	sizeb;
	int	over;
}t_stack;

void	*ft_calloc(size_t count, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *h, const char *nl, size_t n);
void	exiterr(void);
int		ft_atoi(const char *str);
void	checkargs(char *av, int ac, t_stack *stack);
void	listcreating(char **av, t_stack *stack, int j);
char	**ft_split(char const *s, char c);
void	ft_initstack(char **av, int ac, t_stack *stack);
void	sorter(t_stack *stack);
void	sorthree(t_stack *stack);
void	pusha(t_stack *stack);
void	ft_sortfor(t_stack *stack);
void	swapa(t_stack *stack);
void	radixsorter(t_stack *stack);
void	rb(t_stack *stack );
void	ra(t_stack *stack);
int		ft_ifsorted(t_stack *stack, int j);
void	pushb(t_stack *stack);
void	ft_bzero(void *s, size_t n);
void	ft_underthre(t_stack *stack, int i);

#endif