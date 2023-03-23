/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:27:41 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/15 23:20:58 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strnstr(const char *h, const char *nl, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*nl)
		return ((char *)(h));
	if (n <= 0)
		return (NULL);
	while (h[i] && i < n)
	{
		j = 0;
		while (nl[j] && i + j < n)
		{
			if (h[i + j] == nl[j])
			{
				if (nl[j + 1] == '\0')
					return ((char *)h + i);
				j++;
			}
			else
				break ;
		}
		i++;
	}
	return (0);
}
