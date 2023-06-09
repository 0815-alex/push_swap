/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:55 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:34:25 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*buffer_node;

	if (!*from)
		return ;
	buffer_node = *from;
	*from = (*from)->next;
	buffer_node->next = *to;
	*to = buffer_node;
}

long	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
	return (1);
}

long	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
	return (1);
}
