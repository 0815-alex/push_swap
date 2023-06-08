/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:09:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/08 21:05:08 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_by_bit(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int i;
	int h;
	
	h = stack_height(*stack_a);
	// printf("stack height: %i\n",h);
	i = 0;
	while(i < h)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void merge_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while(*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
void sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		bit;

	bit = 0;
	
	while(bit < 8)
	{
		// dbg_printf(start_block, "DO FOR BIT %i", bit);
		
		sort_by_bit(stack_a, stack_b, bit);
		
		// dbg_printf(no_block, "A>");
		// print_stack(*stack_a);
		// dbg_printf(no_block, "B>");
		// print_stack(*stack_b);

		merge_to_a(stack_a, stack_b);
		// dbg_printf(no_block, "MERGED");
		// dbg_printf(no_block, "A>");
		// print_stack(*stack_a);
		// dbg_printf(no_block, "B>");
		// print_stack(*stack_b);
		// dbg_printf(end_block, "DONE FOR BIT %i", bit);
		bit++;
	}
}
