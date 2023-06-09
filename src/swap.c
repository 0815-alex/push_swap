/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:35:30 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*buffer_node;

	if (!*stack || !(*stack)->next)
		return ;
	buffer_node = (*stack)->next;
	(*stack)->next = buffer_node->next;
	buffer_node->next = *stack;
	*stack = buffer_node;
}

long	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
	return (1);
}

long	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
	return (1);
}

long	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return (1);
}
