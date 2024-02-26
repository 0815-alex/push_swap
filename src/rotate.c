/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:44 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 20:05:16 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*buffer_node;

	if (!(*stack))
		return ;
	if ((*stack)->n)
	{
		buffer_node = *stack;
		while ((*stack)->n)
			*stack = (*stack)->n;
		(*stack)->n = buffer_node;
		*stack = buffer_node->n;
		buffer_node->n = NULL;
	}
}

long	ra(t_stacks *stacks, t_bool print)
{
	rotate(&stacks->a);
	if (print)
		ft_printf("ra\n");
	return (1);
}

long	rb(t_stacks *stacks, t_bool print)
{
	rotate(&stacks->b);
	if (print)
		ft_printf("rb\n");
	return (1);
}

long	rr(t_stacks *stacks, t_bool print)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	if (print)
		ft_printf("rr\n");
	return (1);
}
