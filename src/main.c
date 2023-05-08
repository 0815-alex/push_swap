/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:17:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	check_args(int argc, char **argv)
{
	t_bool	result;
	int		i;

	result = ft_true;
	i = 1;
	if (!argc || argc < 1)
		result = ft_false;
	while (i < argc)
	{
		if (ft_itoa(ft_atoi(argv[i])) != argv[i])
		{
			result = ft_false;
			break ;
			i++;
		}
	}
	return (result);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
	}
	else
		ft_putstr_fd()
	return (0);
}
