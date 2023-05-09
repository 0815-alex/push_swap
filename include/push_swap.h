/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:54:25 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 16:16:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef DEBUG
#  define DEBUG 0
# endif

# include "../lib/libft_printf.h"

//******************************************************************************
//			Typedefs
//******************************************************************************

void				ft_debug_printf(char *str, ...);

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;
#endif