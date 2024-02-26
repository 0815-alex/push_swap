/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:27 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 21:56:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_indices(t_stack *stack, t_stack	*s[5])
{
	unsigned int	cur_i;	

	cur_i = 1;
	s[3] = stack;
	while (s[3]->n)
	{
		s[4] = stack;
		s[0] = s[2];
		while (s[4])
		{
			if (!s[4]->index_set && s[4]->value < s[0]->value)
				s[0] = s[4];
			s[4] = s[4]->n;
		}
		set_index(s[0], cur_i);
		cur_i++;
		s[3] = s[3]->n;
	}
}

/*
	buf_stacks
		0	current value
		1	min value
		2	max value
		3	index 1 aka i
		4 	index 2 aka j
*/
static void	ini_indices(t_stack *stack)
{
	t_stack			*s[5];

	s[1] = stack;
	s[2] = stack;
	s[3] = stack;
	while (s[3])
	{
		if (s[3]->value < s[1]->value)
			s[1] = s[3];
		if (s[3]->value > s[2]->value)
			s[2] = s[3];
		s[3] = s[3]->n;
	}
	set_index(s[1], 0);
	set_indices(stack, s);
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
	last_node->n = NULL;
	ini_indices(new_stack);
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
	if (buf)
		free(buf);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
}
