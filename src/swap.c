/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 20:04:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*buffer_node;

	if (!*stack || !(*stack)->n)
		return ;
	buffer_node = (*stack)->n;
	(*stack)->n = buffer_node->n;
	buffer_node->n = *stack;
	*stack = buffer_node;
}

long	sa(t_stacks *stacks, t_bool print)
{
	swap(&stacks->a);
	if (print)
		ft_printf("sa\n");
	return (1);
}

long	sb(t_stacks *stacks, t_bool print)
{
	swap(&stacks->b);
	if (print)
		ft_printf("sb\n");
	return (1);
}

long	ss(t_stacks *stacks, t_bool print)
{
	swap(&stacks->a);
	swap(&stacks->b);
	if (print)
		ft_printf("ss\n");
	return (1);
}
