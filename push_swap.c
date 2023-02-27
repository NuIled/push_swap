/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:48:42 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/26 11:05:47 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{

    t_stack *stacks;

    stacks = malloc(sizeof(t_stack));
    if (!stacks)
        return (printf("Error\n"));
    chek(av,ac, stacks);

    return 0;
}
