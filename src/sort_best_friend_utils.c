/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_friend_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:00:18 by astein            #+#    #+#             */
/*   Updated: 2023/06/13 20:38:46 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/push_swap.h"

// double	get_mean_value(t_stack *stack)
// {
// 	long	sum;
// 	int		count;

// 	sum = 0;
// 	count = 0;
// 	if (stack == NULL)
// 		return (0.0);
// 	while (stack != NULL)
// 	{
// 		sum += stack->i;
// 		count++;
// 		stack = stack->n;
// 	}
// 	return ((double)sum / count);
// }

// /*
// 	BUF			0	long		result;
// 				1	long		cnt_r;
// 				2	long		cnt_rr;

// 	ttb = to top stack b
// */
// static long	ttb(t_stacks *stacks, unsigned int b,
// t_bool do_it, t_bool print)
// {
// 	t_stacks	*stacks_cpy;
// 	long		buf[3];

// 	stacks_cpy = cpy_stacks(stacks);
// 	buf[1] = 0;
// 	buf[2] = 0;
// 	while (stacks_cpy->b->i != b)
// 		buf[1] += rb (stacks_cpy, ft_false);
// 	while (stacks_cpy->b->i != b)
// 		buf[2] += rrb (stacks_cpy, ft_false);
// 	free_stacks(stacks_cpy);
// 	if (buf[1] < buf[2])
// 		buf[0] = buf[1];
// 	else
// 		buf[0] = buf[2];
// 	if (do_it)
// 	{
// 		buf[0] = 0;
// 		if (buf[1] < buf[2])
// 			while (stacks->b->i != b)
// 				buf[0] += rb (stacks, print);
// 		else
// 			while (stacks->b->i != b)
// 				buf[0] += rrb (stacks, print);
// 	}
// 	return (buf[0]);
// }

// /*
// 	BUF			0	long		result;
// 				1	long		cnt_r;
// 				2	long		cnt_rr;
// 	tta = to top stack b
// */
// static long	tta(t_stacks *stacks, unsigned int a,
// t_bool do_it, t_bool print)
// {
// 	t_stacks	*stacks_cpy;
// 	long		buf[3];

// 	stacks_cpy = cpy_stacks(stacks);
// 	buf[1] = 0;
// 	buf[2] = 0;
// 	while (stacks_cpy->a->i != a)
// 		buf[1] += ra (stacks_cpy, ft_false);
// 	while (stacks_cpy->a->i != a)
// 		buf[2] += rra (stacks_cpy, ft_false);
// 	free_stacks(stacks_cpy);
// 	if (buf[1] < buf[2])
// 		buf[0] = buf[1];
// 	else
// 		buf[0] = buf[2];
// 	if (do_it)
// 	{
// 		buf[0] = 0;
// 		if (buf[1] < buf[2])
// 			while (stacks->a->i != a)
// 				buf[0] += ra (stacks, print);
// 		else
// 			while (stacks->a->i != a)
// 				buf[0] += rra (stacks, print);
// 	}
// 	return (buf[0]);
// }

// static void	find_best_cost(t_stack	*s[3])
// {
// 	while (s[0])
// 	{
// 		if (s[0]->bf_c < s[2]->bf_c)
// 			s[2] = s[0];
// 		s[0] = s[0]->n;
// 	}
// }

// /*
// 	cur		0	cur_a
// 			1	cur_b
// 			2	bf
// */
// void	do_best_friend(t_stacks *ss, t_bool p, long *c)
// {
// 	t_stack	*s[3];

// 	s[0] = ss->a;
// 	while (s[0])
// 	{
// 		s[1] = ss->b;
// 		s[2] = s[1];
// 		while (s[1])
// 		{
// 			if ((long)(s[0]->i - s[1]->i) > 0
// 				&& (long)(s[0]->i - s[1]->i) < (long)(s[0]->i - s[2]->i))
// 				s[2] = s[1];
// 			s[1] = s[1]->n;
// 		}
// 		s[0]->bf = s[2];
// 		s[0]->bf_c = tta(ss, s[0]->i, 0, 0) + ttb(ss, s[2]->i, 0, 0);
// 		s[0] = s[0]->n;
// 	}
// 	s[0] = ss->a;
// 	s[2] = s[0];
// 	find_best_cost(s);
// 	*c += tta(ss, s[2]->i, 1, p) + ttb(ss, s[2]->bf->i, 1, p) + pa(ss, p);
// }
