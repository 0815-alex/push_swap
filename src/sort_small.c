/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:02:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/10 04:25:57 by astein           ###   ########.fr       */
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

// void	sort_five(t_stacks	*stacks)
// {
// 	unsigned int	a;
// 	unsigned int	b;
	
// 	pb(&stacks->a, &stacks->b, ft_true);
// 	pb(&stacks->a, &stacks->b, ft_true);
// 	sort_three(stacks);
// 	if (!is_sorted(stacks->b))
// 		rb(&stacks->b, ft_true);
// 	a = stacks->b->i;
// 	b = stacks->b->n->i;
// 	if (a == 0)
// 		pa(&stacks->a, &stacks->b, ft_true);
// 	else if (b == 4)
// 	{
// 		rb(&stacks->b, ft_true);
// 		pa(&stacks->a, &stacks->b, ft_true);
// 	}
// 	else
// 	{
// 		ra(&stacks->a, ft_true);
// 		pa(&stacks->a, &stacks->b, ft_true);
// 	}
// 	smart_rotate2sort(&stacks->a);
// 	dbg_end(stacks);
// }

//12 allowed
void	sort_five(t_stacks	*stacks)
{
	unsigned int	a;
	unsigned int	b;

	pb(&stacks->a, &stacks->b, ft_true);
	pb(&stacks->a, &stacks->b, ft_true);
	sort_three(stacks);
	if (!is_sorted(stacks->b))
		rb(&stacks->b, ft_true);
	a = stacks->b->i;
	b = stacks->b->n->i;
	if (a != 0)
		rb(&stacks->b, ft_true);
	else
		pa(&stacks->a, &stacks->b, ft_true);
	if (a == 3 && b == 4)	
		pa(&stacks->a, &stacks->b, ft_true);
	else if (a == 2 && b == 4)
	{
		pa(&stacks->a, &stacks->b, ft_true);
		rra(&stacks->a, ft_true);
	}
	else if (a == 2 && b == 3)
	{
		rra(&stacks->a, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
	}
	else if (a == 1 && b == 4)
	{
		pa(&stacks->a, &stacks->b, ft_true);
		ra(&stacks->a, ft_true);
		ra(&stacks->a, ft_true);
	}
	else if (a == 1 && b == 3)
	{
		rra(&stacks->a, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
		rra(&stacks->a, ft_true);
	}
	else if (a == 1 && b == 2)
	{
		ra(&stacks->a, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
	}
	else if (a == 0 && b == 3)
		rra(&stacks->a, ft_true);
	else if (a == 0 && b == 2)
	{
		ra(&stacks->a, ft_true);
		ra(&stacks->a, ft_true);
	}
	else if (a == 0 && b == 1)
		ra(&stacks->a, ft_true);
	// smart_rotate2sort(&stacks->a);
	pa(&stacks->a, &stacks->b, ft_true);
	smart_rotate2sort(&stacks->a);
}


//12 allowed
void	sort_five2(t_stacks	*stacks)
{
	pb(&stacks->a, &stacks->b, ft_true);
	pb(&stacks->a, &stacks->b, ft_true);
	sort_three(stacks);
	if (stacks->b->i == 0)
		pa(&stacks->a, &stacks->b, ft_true);
	else if (stacks->b->n && stacks->b->n->i == 0)
	{
		rb(&stacks->b, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
	}
	if (stacks->b->i == 4)
	{
		pa(&stacks->a, &stacks->b, ft_true);
		ra(&stacks->a, ft_true);
	}	
	if (stacks->b && stacks->b->n && stacks->b->n->i == 4)
	{
		rb(&stacks->b, ft_true);
		pa(&stacks->a, &stacks->b, ft_true);
		ra(&stacks->a, ft_true);
	}
	if (!is_sorted(stacks->b))
		rb(&stacks->b, ft_true);
	// dbg_end(stacks);
	while (!is_sorted(stacks->a) || stack_height(stacks->b) != 0)
	{
		if (stacks->b)
		{
			if (stacks->a->i > stacks->b->i)
			{
				pa(&stacks->a, &stacks->b, ft_true);
			}
			else
			{
				// dbg_end(stacks);
				// if (stacks->a->i > 2)
					ra(&stacks->a, ft_true);
				// else
					// rra(&stacks->a, ft_true);
				// smart_rotate2sort(&stacks->a);
			}
		}
		else
		{
			// dbg_end(stacks);
			smart_rotate2sort(&stacks->a);
		}
	}
}
