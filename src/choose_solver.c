/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:30:03 by astein            #+#    #+#             */
/*   Updated: 2023/06/10 01:23:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	check_small_numbers(t_stacks *stacks)
{
	long		amount_of_numbers;
	t_bool		is_small;

	is_small = ft_true;
	amount_of_numbers = stack_height(stacks->a);
	if (amount_of_numbers == 2)
		sort_two(stacks);
	else if (amount_of_numbers == 3)
		sort_three(stacks);
	// else if (amount_of_numbers == 4)
	// 	sort_four(stacks);
	else if (amount_of_numbers == 5)
		sort_five(stacks);
	else
		is_small = ft_false;
	return (is_small);
}

void	*choose_solver(t_stacks *stacks)
{
	t_stacks	*cpy;
	int			count_moves[3];

	if (check_small_numbers(stacks))
		return (NULL);
	cpy = cpy_stacks(stacks);
	count_moves[0] = sort_radix(cpy, ft_false);
	free_stacks(cpy);
	cpy = cpy_stacks(stacks);
	count_moves[1] = INT_MAX;
	free_stacks(cpy);
	cpy = cpy_stacks(stacks);
	count_moves[2] = INT_MAX;
	free_stacks(cpy);
    if (count_moves[0] <= count_moves[1] && count_moves[0] <= count_moves[2])
		sort_radix(stacks, ft_true);
	// else if (count_moves[1] <= count_moves[0] && count_moves[1] <= count_moves[2])
	// else if (count_moves[2] <= count_moves[0] && count_moves[2] <= count_moves[1])
	dbg_printf(no_block, "radix sort mooves: %i", count_moves[0]);
	dbg_printf(no_block, "xy sort mooves: %i", count_moves[1]);
	dbg_printf(no_block, "ab sort mooves: %i", count_moves[2]);
	return (NULL);
}

