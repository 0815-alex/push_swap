/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:30:03 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 21:58:37 by astein           ###   ########.fr       */
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
		sort_three(stacks, ft_true);
	else if (amount_of_numbers == 4)
		sort_radix(stacks, ft_true);
	else if (amount_of_numbers == 5)
		sort_five(stacks, ft_true);
	else
		is_small = ft_false;
	return (is_small);
}

/**
 * @brief	checks wich sort
 * 
 * @param stacks 
 * @return void* 
 */
void	*choose_solver(t_stacks *stacks)
{
	t_stacks	*cpy;

	if (check_small_numbers(stacks))
		return (NULL);
	cpy = cpy_stacks(stacks);
	sort_radix(cpy, ft_false);
	free_stacks(cpy);
	cpy = cpy_stacks(stacks);
	free_stacks(cpy);
	sort_radix(stacks, ft_true);
	return (NULL);
}
