/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:54:25 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:40:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft_printf.h"

//______TYPEDEFS________________________________________________________________
typedef struct s_stack
{
	int				value;
	unsigned int	index;
	t_bool			index_set;
	struct s_stack	*next;
}					t_stack;

void				ft_debug_printf(char *str, ...);

//______PUSH____________________________________________________________________
long				pa(t_stack **a, t_stack **b);
long				pb(t_stack **a, t_stack **b);

//______SWAP____________________________________________________________________
long				sa(t_stack **a);
long				sb(t_stack **b);
long				ss(t_stack **a, t_stack **b);

//______ROTATE__________________________________________________________________
long				ra(t_stack **a);
long				rb(t_stack **b);
long				rr(t_stack **a, t_stack **b);

//______REVERSE ROTATE__________________________________________________________
long				rra(t_stack **a);
long				rrb(t_stack **b);
long				rrr(t_stack **a, t_stack **b);

//______STACK.C_________________________________________________________________
t_stack				*ini_stack_a(int argc, char **argv);
void				free_stack(t_stack *stack);

//______STACK_UTILS.C___________________________________________________________
t_bool				is_sorted(t_stack *stack);
int					stack_height(t_stack *stack);
void				set_index(t_stack *node, long i);
void				print_stack(t_stack *stack);
t_stack				*cpy_stack(t_stack **stack_a);

//******************************************************************************
//			SOLVERS -> radix.c
//******************************************************************************
long				sort_radix(t_stack **stack_a, t_stack **stack_b);
void				choose_solver(t_stack **stack_a, t_stack **stack_b);

#endif