/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:08:45 by astein            #+#    #+#             */
/*   Updated: 2023/06/13 16:47:32 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		ft_printf("(null)");
	while (stack)
	{
		ft_printf("%i ", (int)stack->i);
		stack = stack->n;
	}
	ft_printf("\n");
}

void	print_stacks(t_stacks *stacks)
{
	ft_printf("A: ");
	print_stack(stacks->a);
	ft_printf("B: ");
	print_stack(stacks->b);
}

void	dbg_end(t_stacks *stacks)
{
	print_stacks(stacks);
	exit(0);
}
