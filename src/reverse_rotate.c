/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:42 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 16:29:27 by astein           ###   ########.fr       */
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

long	rra(t_stack **a, t_bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
	return (1);
}

long	rrb(t_stack **b, t_bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
	return (1);
}

long	rrr(t_stack **a, t_stack **b, t_bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
	return (1);
}
