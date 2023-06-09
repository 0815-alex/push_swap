/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/09 14:43:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	result = ft_true;
	i = 1;
	if (argc <= 1)
		result = ft_false;
	while (i < argc)
	{
		v[0] = ft_itoa(ft_atoi(argv[i]));
		if (ft_strlen(argv[i]) != ft_strlen(v[0])
			|| ft_strncmp(argv[i], v[0], ft_strlen(argv[i]) != 0))
			dbg_printf(err_block, "Error");
		j = 1;
		while (j < i)
		{
			v[1] = ft_itoa(ft_atoi(argv[j]));
			if (ft_strlen(v[1]) == ft_strlen(v[0]) && ft_strncmp(v[1], v[0],
					ft_strlen(argv[j])) == 0)
				dbg_printf(err_block, "Error");
			free(v[1]);
			j++;
		}
		free(v[0]);
		if (result == ft_false)
			break ;
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (check_args(argc, argv) == ft_true)
	{
		stack_a = ini_stack_a(argc, argv);
		if (!stack_a)
			return (1);
		dbg_printf(no_block, "stack height: %i", stack_height(stack_a));
		choose_solver(&stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
		ft_printf("Error\n");
	return (0);
}
