/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:54:25 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 21:54:11 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft_gnl_printf.h"

//______TYPEDEFS________________________________________________________________
typedef struct s_stack
{
	int				value;
	unsigned int	i;
	t_bool			index_set;
	struct s_stack	*n;
	struct s_stack	*bf;
	long			bf_c;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

void				ft_debug_printf(char *str, ...);

//______MAIN____________________________________________________________________
int					main(int argc, char **argv);
void				err_exit(char *msg);

//______PUSH____________________________________________________________________
long				pa(t_stacks *stacks, t_bool print);
long				pb(t_stacks *stacks, t_bool print);

//______SWAP____________________________________________________________________
long				sa(t_stacks *stacks, t_bool print);
long				sb(t_stacks *stacks, t_bool print);
long				ss(t_stacks *stacks, t_bool print);

//______ROTATE__________________________________________________________________
long				ra(t_stacks *stacks, t_bool print);
long				rb(t_stacks *stacks, t_bool print);
long				rr(t_stacks *stacks, t_bool print);

//______REVERSE ROTATE__________________________________________________________
long				rra(t_stacks *stacks, t_bool print);
long				rrb(t_stacks *stacks, t_bool print);
long				rrr(t_stacks *stacks, t_bool print);

//______CHECK_ARGV.C____________________________________________________________
void				check_args(int argc, char **argv, t_stacks *stacks);

//______DEBUG.C_________________________________________________________________
void				print_stack(t_stack *stack);
void				print_stacks(t_stacks *stacks);
void				dbg_end(t_stacks *stacks);

//______STACK.C_________________________________________________________________
t_stack				*ini_stack_a(int argc, char **argv);
void				free_stack(t_stack *stack);
void				free_stacks(t_stacks *stacks);

//______STACK_UTILS.C___________________________________________________________
t_bool				is_sorted(t_stack *stack);
int					stack_height(t_stack *stack);
void				set_index(t_stack *node, long i);
t_stack				*cpy_stack(t_stack **stack_a);
t_stacks			*cpy_stacks(t_stacks *stacks);

//______CHOOSE_SOLVER.C_________________________________________________________
void				*choose_solver(t_stacks *stacks);

//______SORT_SMALL.C____________________________________________________________
void				sort_two(t_stacks	*stacks);
long				sort_three(t_stacks	*s, t_bool print);
long				sort_five(t_stacks	*stacks, t_bool print);

//______SORT_RADIX.C____________________________________________________________
long				sort_radix(t_stacks	*stacks, t_bool print);

//______SORT_BEST_FRIEND.C______________________________________________________
long				sort_best_friend(t_stacks	*stacks, t_bool print);

//______SORT_BEST_FRIEND_UTILS.C________________________________________________
double				get_mean_value(t_stack *stack);
void				do_best_friend(t_stacks *ss, t_bool p, long *c);

#endif
