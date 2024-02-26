/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 23:00:38 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void err_exit(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	stacks->a = NULL;
	stacks->b = NULL;
	check_args(argc, argv, stacks);
	stacks->a = ini_stack_a(argc, argv);
	if (!stacks->a)
		return (1);
	if (!is_sorted(stacks->a))
		choose_solver(stacks);
	free_stacks(stacks);
	return (0);
}
