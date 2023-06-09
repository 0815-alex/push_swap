/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:54:25 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 17:06:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft_printf.h"

//______TYPEDEFS________________________________________________________________
typedef struct s_stack
{
	int				value;
	unsigned int	i;
	t_bool			index_set;
	struct s_stack	*n;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;


void				ft_debug_printf(char *str, ...);

//______PUSH____________________________________________________________________
long				pa(t_stack **a, t_stack **b, t_bool print);
long				pb(t_stack **a, t_stack **b, t_bool print);

//______SWAP____________________________________________________________________
long				sa(t_stack **a, t_bool print);
long				sb(t_stack **b, t_bool print);
long				ss(t_stack **a, t_stack **b, t_bool print);

//______ROTATE__________________________________________________________________
long				ra(t_stack **a, t_bool print);
long				rb(t_stack **b, t_bool print);
long				rr(t_stack **a, t_stack **b, t_bool print);

//______REVERSE ROTATE__________________________________________________________
long				rra(t_stack **a, t_bool print);
long				rrb(t_stack **b, t_bool print);
long				rrr(t_stack **a, t_stack **b, t_bool print);

//______STACK.C_________________________________________________________________
t_stack				*ini_stack_a(int argc, char **argv);
void				free_stack(t_stack *stack);
void				free_stacks(t_stacks *stacks);

//______STACK_UTILS.C___________________________________________________________
t_bool				is_sorted(t_stack *stack);
int					stack_height(t_stack *stack);
void				set_index(t_stack *node, long i);
void				print_stack(t_stack *stack);
t_stack				*cpy_stack(t_stack **stack_a);

//******************************************************************************
//			SOLVERS -> radix.c
//******************************************************************************
long	sort_radix(t_stacks	*stacks, t_bool print);
void				*choose_solver(t_stacks *stacks);
t_stacks	*cpy_stacks(t_stacks *stacks);

void				sort_two(t_stacks	*stacks);
void				sort_three(t_stacks	*stacks);
void				sort_four(t_stacks	*stacks);
void				sort_five(t_stacks	*stacks);

#endif