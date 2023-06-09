/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 16:29:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_bool	is_sorted(t_stack *stack)
{
	unsigned int	i;

	if (stack)
	{
		i = stack->i;
		stack = stack->n;
		while (stack)
		{
			if (stack->i < i)
				return (ft_false);
			else
				i = stack->i;
			stack = stack->n;
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
		stack = stack->n;
	}
	return (height);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
		ft_printf("(null)");
	while (stack)
	{
		// ft_printf("(%i [%i]) < ", stack->value, (int)stack->i);
		// ft_printf("%i ", stack->value);
		ft_printf("%i ", (int)stack->i);
		stack = stack->n;
	}
	ft_printf("\n");
}

void	set_index(t_stack *node, long i)
{
	if (i == -1)
	{
		node->i = 0;
		node->index_set = ft_false;
	}
	else
	{
		node->i = (unsigned int)i;
		node->index_set = ft_true;
	}
}

t_stacks	*cpy_stacks(t_stacks *stacks)
{
	t_stacks	*cpy;

	cpy = malloc(sizeof(t_stacks));
	if (!cpy)
		return (NULL);
	cpy->a = cpy_stack(&stacks->a);
	cpy->b = cpy_stack(&stacks->b);
	return (cpy);
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
		cpy_pointer->i = buf->i;
		cpy_pointer->index_set = buf->index_set;
		buf = buf->n;
		if (buf)
		{
			cpy_pointer->n = malloc(sizeof(t_stack));
			if (!cpy_pointer->n)
				return (NULL);
			cpy_pointer = cpy_pointer->n;
		}
	}
	cpy_pointer->n = NULL;
	return (cpy_first);
}
