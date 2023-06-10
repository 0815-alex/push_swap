/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:44 by astein            #+#    #+#             */
/*   Updated: 2023/06/10 03:22:35 by astein           ###   ########.fr       */
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
			*stack = (*stack)->n;    //find the end
		(*stack)->n = buffer_node;   //link start to end (end next -> start)
		*stack = buffer_node->n;     //set the start to old starts next
		buffer_node->n = NULL;       //set old starts bext to null
	}
}

long	ra(t_stack **a, t_bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
	return (1);
}

long	rb(t_stack **b, t_bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
	return (1);
}

long	rr(t_stack **a, t_stack **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
	return (1);
}

void	smart_rotate2sort(t_stack **stack)
{
	t_stack	*buf1;
	int		count[2];

	if (!is_sorted(*stack))
	{
		count[0] = 0;
		count[1] = 0;
		buf1 = cpy_stack(stack);
		while (!is_sorted(buf1))
				count[0] += ra(&buf1, ft_false);
		free_stack(buf1);
		buf1 = cpy_stack(stack);
		while (!is_sorted(buf1))
			count[1] += rra(&buf1, ft_false);
		free_stack(buf1);
		if (count[0] < count[1])
		{
			while (!is_sorted(*stack))
				ra(stack, ft_true);
		}
		else
		{
			while (!is_sorted(*stack))
				rra(stack, ft_true);
		}
	}
}
