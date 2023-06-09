/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:44 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:35:11 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
 t_stack	*buffer_node;

	if (!(*stack))
		return ;
	if ((*stack)->next)
	{                                   //START -> END
		buffer_node = *stack;           //safe the start
		while ((*stack)->next)          
			*stack = (*stack)->next;    //find the end
		(*stack)->next = buffer_node;   //link start to end (end next -> start)
		*stack = buffer_node->next;     //set the start to old starts next
		buffer_node->next = NULL;       //set old starts bext to null
	}
}

long	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
	return (1);
}

long	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
	return (1);
}

long	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return (1);
}
