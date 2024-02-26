/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:55 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 15:22:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stacks *stacks, t_bool a2b)
{
	t_stack	*buffer_node;

	if (!stacks)
		return ;
	if (a2b)
	{
		if (!stacks->a)
			return ;
		buffer_node = stacks->a;
		stacks->a = stacks->a->n;
		buffer_node->n = stacks->b;
		stacks->b = buffer_node;
	}
	else
	{
		if (!stacks->b)
			return ;
		buffer_node = stacks->b;
		stacks->b = stacks->b->n;
		buffer_node->n = stacks->a;
		stacks->a = buffer_node;
	}
}

long	pa(t_stacks *stacks, t_bool print)
{
	push(stacks, ft_false);
	if (print)
		ft_printf("pa\n");
	return (1);
}

long	pb(t_stacks *stacks, t_bool print)
{
	push(stacks, ft_true);
	if (print)
		ft_printf("pb\n");
	return (1);
}
