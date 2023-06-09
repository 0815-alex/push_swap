/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:30:03 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:45:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	choose_solver(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cpy;
	int		count_moves[1];

	cpy = cpy_stack(stack_a);
	count_moves[0] = sort_radix(&cpy, stack_b);
	free_stack(cpy);
	dbg_printf(no_block, "radix sort mooves: %i", count_moves[0]);
}

