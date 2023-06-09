/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:02:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 20:22:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stacks	*stacks)
{
	ra(&stacks->a, ft_true);
}

void	sort_three(t_stacks	*s)
{
	int		a;
	int		b;
	int		c;

	a = s->a->i;
	b = s->a->n->i;
	c = s->a->n->n->i;
	if (a > b && b < c && c > a)
		sa(&s->a, ft_true);
	else if (a > b && b < c && c < a)
		ra(&s->a, ft_true);
	else if (a < b && b > c && c < a)
		rra(&s->a, ft_true);
	else if (a > b && b > c && c < a)
	{
		sa(&s->a, ft_true);
		rra(&s->a, ft_true);
	}
	else if (a < b && b > c && c > a)
	{
		sa(&s->a, ft_true);
		ra(&s->a, ft_true);
	}
}

// void	sort_four(t_stacks	*stacks)
// {
	
// }


//12 allowed
void	sort_five(t_stacks	*stacks)
{
	pb(&stacks->a, &stacks->b, ft_true);
	pb(&stacks->a, &stacks->b, ft_true);
	//	2/12
	sort_three(stacks);
	//	4/12
	print_stack(stacks->a);
	print_stack(stacks->b);
	if (stacks->b->i == 0)
		pa(&stacks->a, &stacks->b, ft_true);
		//	5/12
	else if (stacks->b->n->i == 0)
	{
		rb(&stacks->b, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
		//	6/12
	}
	if (stacks->b->i == 4)
	{
		pa(&stacks->a, &stacks->b, ft_true);
		ra(&stacks->a, ft_true);
		//max 8/12
	}	
	if (stacks->b->n && stacks->b->n->i == 4)
	{
		rb(&stacks->b, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
		ra(&stacks->a, ft_true);
		//max 8/12
	}
		
	
	
	

	
	// while (!is_sorted(stacks->a) || stack_height(stacks->b) != 0)
	// {
	// 	if (stacks->b)
	// 	{
	// 		if (stacks->a->i > stacks->b->i)
	// 			pa(&stacks->a, &stacks->b, ft_true);
	// 		else
	// 			ra(&stacks->a, ft_true);
	// 	}
	// 	else
	// 		ra(&stacks->a, ft_true);
	// 	print_stack(stacks->a);
	// 	print_stack(stacks->b);
	// }
}
