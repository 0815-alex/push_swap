/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:42 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 22:12:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
    t_stack	*buffer_node;

	if (!(*stack))
		return ;
	if ((*stack)->next)
	{                                   //END -> START
		buffer_node = *stack;           //safe the start
		while ((*stack)->next->next)          
			*stack = (*stack)->next;    //find the second last
        (*stack)->next->next = buffer_node;
        buffer_node = (*stack)->next;
		(*stack)->next = NULL;
        *stack = buffer_node;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
