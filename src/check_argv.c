/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:50 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 21:55:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief	checks if the param is an valid int and returns it as a string
 * 
 * @param	a
 * @return	char* 
 */
static char	*check_args_number(char *a)
{
	char	*b;

	b = ft_itoa(ft_atoi(a));
	if (ft_strlen(a) != ft_strlen(b) || ft_strncmp(a, b, ft_strlen(a) != 0))
	{
		free(b);
		return ("e");
	}
	return (b);
}

static void	check_args_duplicate(int i, char *a, char **argv, t_stacks *stacks)
{
	int		j;
	char	*b;

	j = 1;
	while (j < i)
	{
		b = ft_itoa(ft_atoi(argv[j]));
		if (ft_strlen(b) == ft_strlen(a) && ft_strncmp(b, a,
				ft_strlen(argv[j])) == 0)
		{
			free_stacks(stacks);
			free(a);
			free(b);
			err_exit("error: Duplicate");
		}
		free(b);
		j++;
	}
}

/**
 *    v = values
 * 			0 = value from args from a to i and then from i to a
 * 			1 = compare value to check dublicates
*/
void	check_args(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	char	*a;

	i = 1;
	if (argc <= 1)
		err_exit("error: No arguments");
	while (i < argc)
	{
		a = check_args_number(argv[i]);
		if (ft_strncmp(a, "e", 1) == 0)
		{
			free_stacks(stacks);
			err_exit("error: Invalid argument");
		}
		check_args_duplicate(i, a, argv, stacks);
		free(a);
		i++;
	}
}
