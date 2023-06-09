/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:36:33 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_bool	is_sorted(t_stack *stack)
{
	unsigned int	i;

	if (stack)
	{
		i = stack->index;
		stack = stack->next;
		while (stack)
		{
			if (stack->index < i)
				return (ft_false);
			else
				i = stack->index;
			stack = stack->next;
		}
		return (ft_true);
	}
	return (ft_false);
}

int	stack_height(t_stack *stack)
{
	int	height;

	height = 0;
	while (stack)
	{
		height++;
		stack = stack->next;
	}
	return (height);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
		ft_printf("(null)");
	while (stack)
	{
		// ft_printf("(%i [%i]) < ", stack->value, (int)stack->index);
		// ft_printf("%i ", stack->value);
		ft_printf("%i ", (int)stack->index);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	set_index(t_stack *node, long i)
{
	if (i == -1)
	{
		node->index = 0;
		node->index_set = ft_false;
	}
	else
	{
		node->index = (unsigned int)i;
		node->index_set = ft_true;
	}
}

t_stack	*cpy_stack(t_stack **stack_a)
{
	t_stack	*buf;
	t_stack	*cpy_first;
	t_stack	*cpy_pointer;

	cpy_first = malloc(sizeof(t_stack));
	if (!cpy_first)
		return (NULL);
	buf = *stack_a;
	cpy_pointer = cpy_first;
	while (buf)
	{
		cpy_pointer->value = buf->value;
		cpy_pointer->index = buf->index;
		cpy_pointer->index_set = buf->index_set;
		buf = buf->next;
		if (buf)
		{
			cpy_pointer->next = malloc(sizeof(t_stack));
			if (!cpy_pointer->next)
				return (NULL);
			cpy_pointer = cpy_pointer->next;
		}
	}
	cpy_pointer->next = NULL;
	return (cpy_first);
}
