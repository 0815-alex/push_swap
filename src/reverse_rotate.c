/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:42 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 20:05:55 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*buffer_node;

	if (!(*stack))
		return ;
	if ((*stack)->n)
	{
		buffer_node = *stack;
		while ((*stack)->n->n)
			*stack = (*stack)->n;
		(*stack)->n->n = buffer_node;
		buffer_node = (*stack)->n;
		(*stack)->n = NULL;
		*stack = buffer_node;
	}
}

long	rra(t_stacks *stacks, t_bool print)
{
	reverse_rotate(&stacks->a);
	if (print)
		ft_printf("rra\n");
	return (1);
}

long	rrb(t_stacks *stacks, t_bool print)
{
	reverse_rotate(&stacks->b);
	if (print)
		ft_printf("rrb\n");
	return (1);
}

long	rrr(t_stacks *stacks, t_bool print)
{
	reverse_rotate(&stacks->a);
	reverse_rotate(&stacks->b);
	if (print)
		ft_printf("rrr\n");
	return (1);
}
