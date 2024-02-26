/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_friend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:51:04 by astein            #+#    #+#             */
/*   Updated: 2023/06/13 20:38:58 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// 	thx to duarte3333 for the idea
// 	-> https://github.com/duarte3333/Push_Swap
// */
// #include "../include/push_swap.h"

// long	sort_best_friend(t_stacks	*stacks, t_bool print)
// {
// 	long	count_actions;
// 	double	mean;

// 	count_actions = 0;
// 	while (stack_height(stacks->a) > 3)
// 	{
// 		mean = get_mean_value(stacks->a);
// 		if (stacks->a->i < mean)
// 			count_actions += pb(stacks, print);
// 		else
// 			count_actions += ra(stacks, print);
// 	}
// 	count_actions += sort_three(stacks, print);
// 	while (stack_height(stacks->b) > 0)
// 	{
// 		do_best_friend(stacks, print, &count_actions);
// 		// print_stacks(stacks);
// 	}
// 	return (count_actions);
// }
