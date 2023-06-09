/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:55 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 16:29:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*buffer_node;

	if (!*from)
		return ;
	buffer_node = *from;
	*from = (*from)->n;
	buffer_node->n = *to;
	*to = buffer_node;
}

long	pa(t_stack **a, t_stack **b, t_bool print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
	return (1);
}

long	pb(t_stack **a, t_stack **b, t_bool print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
	return (1);
}
