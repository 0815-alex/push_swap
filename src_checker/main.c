/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:46 by astein            #+#    #+#             */
/*   Updated: 2024/02/26 23:00:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	stacks->b = NULL;
	check_args(argc, argv, stacks);
	stacks->a = ini_stack_a(argc, argv);
	if (!stacks->a)
		return (1);
	start_check(stacks);
	free_stacks(stacks);
	return (0);
}
void err_exit(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}