/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 01:20:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	check_args(int argc, char **argv)
{
	t_bool	result;
	int		i;
	int		j;
	char	*cleaned_value;
	char	*cleaned_value2;

	result = ft_true;
	i = 1;
	ft_debug_printf("Argument Count:%d\n", argc);
	if (argc <= 1)
		result = ft_false;
	while (i < argc)
	{
		cleaned_value = ft_itoa(ft_atoi(argv[i]));
		ft_debug_printf("\n>%s< (pure arg)\n", argv[i]);
		ft_debug_printf(">%s< (cleand arg)\n\n", cleaned_value);
		if (ft_strlen(argv[i]) != ft_strlen(cleaned_value) ||
			ft_strncmp(argv[i], cleaned_value, ft_strlen(argv[i]) != 0))
		{
			ft_debug_printf("Value >%s< not valid!\n\n", argv[i]);
			result = ft_false;
			break ;
		}
		j = 1;
		while (j < i)
		{
			cleaned_value2 = ft_itoa(ft_atoi(argv[j]));
			ft_debug_printf("Compare:>%s< and >%s<\n", cleaned_value, cleaned_value2);
			if (ft_strlen(cleaned_value2) == ft_strlen(cleaned_value)
				&& ft_strncmp(cleaned_value2, cleaned_value,
					ft_strlen(argv[j])) == 0)
			{
				ft_debug_printf("Value >%s< is a duplicate!\n\n", argv[j]);
				result = ft_false;
				break ;
			}
			j++;
		}
		if (result == ft_false)
			break ;
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	ft_debug_printf("\n---------\nDEBUG ON!\n---------\n\n");
	if (check_args(argc, argv) == ft_true)
	{
		ft_debug_printf("\nInput arguments are fine...\n");
	}
	else
	{
		ft_printf("Error\n");
	}
	return (0);
}
