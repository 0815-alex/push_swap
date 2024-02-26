/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:02:46 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 21:55:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stacks	*stacks)
{
	if (!is_sorted(stacks->a))
		ra(stacks, ft_true);
}

long	sort_three(t_stacks	*s, t_bool print)
{
	int		buf[3];
	long	count_actions;

	count_actions = 0;
	buf[0] = s->a->i;
	buf[1] = s->a->n->i;
	buf[2] = s->a->n->n->i;
	if (buf[0] > buf[1] && buf[1] < buf[2] && buf[2] > buf[0])
		count_actions += sa(s, print);
	else if (buf[0] > buf[1] && buf[1] < buf[2] && buf[2] < buf[0])
		count_actions += ra(s, print);
	else if (buf[0] < buf[1] && buf[1] > buf[2] && buf[2] < buf[0])
		count_actions += rra(s, print);
	else if (buf[0] > buf[1] && buf[1] > buf[2] && buf[2] < buf[0])
	{
		count_actions += sa(s, print);
		count_actions += rra(s, print);
	}
	else if (buf[0] < buf[1] && buf[1] > buf[2] && buf[2] > buf[0])
	{
		count_actions += sa(s, print);
		count_actions += ra(s, print);
	}
	return (count_actions);
}

/**
 * @brief	checks if ra or rra is more efficient to bring the element with
 * 			the index i to the top.
 * 
 * 			NOTE:
 * 					- only made for stack heights 4 and 5
 * 					- only made for stack a
 * 
 * @param stack	the stack
 * @param i 	the index that should be brought on top
 */
static long	push_to_top(t_stacks *stacks, unsigned int i, t_bool print)
{
	long	count_actions;

	count_actions = 0;
	if (stacks->a->i == i || stacks->a->n->i == i || stacks->a->n->n->i == i)
	{
		while (stacks->a->i != i)
			count_actions += ra(stacks, print);
	}
	else
	{
		while (stacks->a->i != i)
			count_actions += rra(stacks, print);
	}
	return (count_actions);
}

/*
	index 0 push b
	index 1 push b
	3 sortieren
	pa
	pa
	
*/
long	sort_five(t_stacks	*stacks, t_bool print)
{
	long	count_actions;

	count_actions = 0;
	if (stack_height(stacks->a) == 5)
	{
		count_actions += push_to_top(stacks, 0, print);
		count_actions += pb(stacks, print);
		count_actions += push_to_top(stacks, 1, print);
		count_actions += pb(stacks, print);
		count_actions += sort_three(stacks, print);
		count_actions += pa(stacks, print);
		count_actions += pa(stacks, print);
	}
	else
		err_exit("error: sort 5 function with a stack != 5 elements!");
	return (count_actions);
}
