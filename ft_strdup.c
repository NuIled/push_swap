/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:07:11 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/21 04:25:02 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1 )
{
	char	*s;
	size_t	i;

	i = ft_strlen(s1) + 1;
	s = malloc(i);
	if (s == 0)
		return (NULL);
	ft_strlcpy (s, s1, i);
	return (s);
}
