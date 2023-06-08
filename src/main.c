/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 00:19:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		stack_height(t_stack *stack)
{
	int height;

	height = 0;
	while(stack)
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
		ft_printf("(%i [%i]) < ", stack->value, (int)stack->index);
		stack = stack->next;
	}
	ft_printf("\n");
}

static void set_indices(t_stack *stack)
{
	t_stack *min_value;
	t_stack *max_value;
	t_stack *cur_value;
	t_stack *buf;
	t_stack *buf2;
	long		cur_i;

	dbg_printf(start_block, "set_indices");
	min_value = stack;
	max_value = stack;
	buf = stack;
	while(buf)
	{
		if(buf->value < min_value->value)
			min_value = buf;
		if(buf->value > max_value->value)
			max_value = buf;
		buf = buf->next;
	}
	min_value->index = 0;
	cur_i = 1;
	buf = stack;
	while(buf->next)
	{
		buf2 = stack;
		cur_value = max_value;
		while(buf2)
		{
			if(buf2->index == -1 && buf2->value < cur_value->value)
				cur_value = buf2;
			buf2= buf2->next;
		}
		cur_value->index = cur_i;
		cur_i++;
		buf= buf->next;
	}
	dbg_printf(end_block, "set_indices");
}

static t_stack	*ini_stack_a(int argc, char **argv)
{
	t_stack	*new_stack;
	t_stack	*last_node;
	int		i;

	dbg_printf(start_block, "ini_stack_a");
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = ft_atoi(argv[1]);
	new_stack->index = -1;
	dbg_printf(no_lb_block, "add %s ", argv[1]);
	last_node = new_stack;
	i = 2;
	while (i < argc)
	{
		last_node->next = malloc(sizeof(t_stack));
		if (!last_node->next)
			return (NULL);
		last_node = last_node->next;
		last_node->value = ft_atoi(argv[i]);
		last_node->index = -1;
		dbg_printf(no_lb_block, "add %s ", argv[i]);
		i++;
	}
	dbg_printf(no_block, "");
	last_node->next = NULL;
	set_indices(new_stack);
	dbg_printf(end_block, "ini_stack_a");
	return (new_stack);
}

/**
 *    v = values
 * 			0 = value from args from a to i and then from i to a
 * 			1 = compare value to check dublicates
*/
static t_bool	check_args(int argc, char **argv)
{
	t_bool	result;
	int		i;
	int		j;
	char	*v[2];

	dbg_printf(start_block, "check_args");
	result = ft_true;
	i = 1;
	if (argc <= 1)
		result = ft_false;
	while (i < argc)
	{
		v[0] = ft_itoa(ft_atoi(argv[i]));
		dbg_printf(no_lb_block, " || > %s <> %s <", argv[i], v[0]);
		if (ft_strlen(argv[i]) != ft_strlen(v[0]) ||
			ft_strncmp(argv[i], v[0], ft_strlen(argv[i]) != 0))
		{
			dbg_printf(err_block, "Error");
			// ft_debug_printf("Value >%s< not valid!\n\n", argv[i]);
			// result = ft_false;
			// break ;
		}
		j = 1;
		while (j < i)
		{
			v[1] = ft_itoa(ft_atoi(argv[j]));
			if (ft_strlen(v[1]) == ft_strlen(v[0]) && ft_strncmp(v[1], v[0],
					ft_strlen(argv[j])) == 0)
			{
				dbg_printf(err_block, "Error");
				// result = ft_false;
				// break ;
			}
			free(v[1]);
			j++;
		}
		free(v[0]);
		if (result == ft_false)
			break ;
		i++;
	}
	dbg_printf(no_block, "");
	dbg_printf(end_block, "check_args");
	return (result);
}

void		free_stack(t_stack *stack)
{
	t_stack *buf;
		while (stack)
		{
			buf = stack->next;
			free(stack);
			stack = buf;
		}
	free(buf);
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// int		count_moves;

	dbg_printf(start_block, "main");
	stack_b = NULL;
	// count_moves = 0;
	if (check_args(argc, argv) == ft_true)
	{
		stack_a = ini_stack_a(argc, argv);
		if (!stack_a)
			return (1);
		// dbg_printf(no_block, "A>");
		// print_stack(stack_a);
		// dbg_printf(no_block, "B>");
		// print_stack(stack_b);

		sort_radix(&stack_a, &stack_b);

		// dbg_printf(no_block, "A>");
		print_stack(stack_a);
		// dbg_printf(no_block, "B>");
		// print_stack(stack_b);
	
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
	{
		ft_printf("Error\n");
	}
	dbg_printf(end_block, "main");
	return (0);
}
