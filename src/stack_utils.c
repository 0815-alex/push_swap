/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/13 17:32:54 by astein           ###   ########.fr       */
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

/*
	0	t_stack	*buf;
	1	t_stack	*cpy_first;
	2	t_stack	*cpy_pointer;
*/
t_stack	*cpy_stack(t_stack **stack)
{
	t_stack	*buf[3];

	if (!*stack)
		return (NULL);
	buf[1] = malloc(sizeof(t_stack));
	if (!buf[1])
		return (NULL);
	buf[0] = *stack;
	buf[2] = buf[1];
	while (buf[0])
	{
		buf[2]->value = buf[0]->value;
		buf[2]->i = buf[0]->i;
		buf[2]->index_set = buf[0]->index_set;
		buf[0] = buf[0]->n;
		if (buf[0])
		{
			buf[2]->n = malloc(sizeof(t_stack));
			if (!buf[2]->n)
				return (NULL);
			buf[2] = buf[2]->n;
		}
	}
	buf[2]->n = NULL;
	return (buf[1]);
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
