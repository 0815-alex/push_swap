/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:09:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:51:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_by_bit(t_stack **stack_a, t_stack **stack_b, int bit, long *count, t_bool asd)
{
	int	i;
	int	h;

	h = stack_height(*stack_a);
	i = 0;
	while (i < h)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
			*count += pb(stack_a, stack_b);
		else
			*count += ra(stack_a);
		i++;
	}
}

void	merge_to_a(t_stack **stack_a, t_stack **stack_b, long *count)
{
	while (*stack_b)
		*count += pa(stack_a, stack_b);
}

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
long	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		bit;
	long	count;

	bit = 0;
	count = 0;
	while (bit < 32)
	{
		if (!is_sorted(*stack_a))
		{
			sort_by_bit(stack_a, stack_b, bit, &count);
			merge_to_a(stack_a, stack_b, &count);
		}
		bit++;
	}
	return (count);
}
