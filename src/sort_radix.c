/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:09:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 16:29:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_by_bit(t_stacks *stacks, int bit, long *count, t_bool print)
{
	int	i;
	int	h;

	h = stack_height(stacks->a);
	i = 0;
	while (i < h)
	{
		if (((stacks->a->i >> bit) & 1) == 0)
			*count += pb(&stacks->a, &stacks->b, print);
		else
			*count += ra(&stacks->a, print);
		i++;
	}
}

static void	merge_to_a(t_stacks *stacks, long *count, t_bool print)
{
	while (stacks->b)
		*count += pa(&stacks->a, &stacks->b, print);
}

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
long	sort_radix(t_stacks	*stacks, t_bool print)
{
	int		bit;
	long	count;

	bit = 0;
	count = 0;
	while (bit < 32)
	{
		if (!is_sorted(stacks->a))
		{
			sort_by_bit(stacks, bit, &count, print);
			merge_to_a(stacks, &count, print);
		}
		bit++;
	}
	return (count);
}
