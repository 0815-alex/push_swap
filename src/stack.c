/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:27 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 16:29:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void set_indices(t_stack *stack)
{
	t_stack			*min_value;
	t_stack			*max_value;
	t_stack			*cur_value;
	t_stack			*buf;
	t_stack			*buf2;
	unsigned int	cur_i;

	min_value = stack;
	max_value = stack;
	buf = stack;
	while (buf)
	{
		if (buf->value < min_value->value)
			min_value = buf;
		if (buf->value > max_value->value)
			max_value = buf;
		buf = buf->n;
	}
	set_index(min_value, 0);
	cur_i = 1;
	buf = stack;
	while (buf->n)
	{
		buf2 = stack;
		cur_value = max_value;
		while (buf2)
		{
			if (!buf2->index_set && buf2->value < cur_value->value)
				cur_value = buf2;
			buf2 = buf2->n;
		}
		set_index(cur_value, cur_i);
		cur_i++;
		buf = buf->n;
	}
}

t_stack	*ini_stack_a(int argc, char **argv)
{
	t_stack	*new_stack;
	t_stack	*last_node;
	int		i;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = ft_atoi(argv[1]);
	set_index(new_stack, -1);
	last_node = new_stack;
	i = 2;
	while (i < argc)
	{
		last_node->n = malloc(sizeof(t_stack));
		if (!last_node->n)
			return (NULL);
		last_node = last_node->n;
		last_node->value = ft_atoi(argv[i]);
		set_index(last_node, -1);
		i++;
	}
	dbg_printf(no_block, "");
	last_node->n = NULL;
	set_indices(new_stack);
	return (new_stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*buf;

	while (stack)
	{
		buf = stack->n;
		free(stack);
		stack = buf;
	}
	free(buf);
}

void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
