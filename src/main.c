/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 16:43:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d<", stack->value);
		stack = stack->next;
	}
}

static t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*new_stack;
	t_stack	*new_node;
	int		i;

	ft_debug_printf("Creating new Stack a...\n");
	new_stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->value = ft_atoi(argv[i]);
		ft_debug_printf("add %s ", argv[i]);
		if (new_stack)
		{
			new_node->next = new_stack;
			new_stack = new_node;
		}
		else
			new_stack = new_node;
		i++;
	}
	ft_debug_printf("\nStack a created:\n");
	return (new_stack);
}

static t_bool	check_args(int argc, char **argv)
{
	t_bool	result;
	int		i;
	int		j;
	char	*cleaned_value;
	char	*cleaned_value2;

	result = ft_true;
	i = 1;
	if (argc <= 1)
		result = ft_false;
	ft_debug_printf("Check args (int and no duplicate):\n");
	while (i < argc)
	{
		cleaned_value = ft_itoa(ft_atoi(argv[i]));
		ft_debug_printf(" || > %s <> %s <", argv[i], cleaned_value);
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
			if (ft_strlen(cleaned_value2) == ft_strlen(cleaned_value)
				&& ft_strncmp(cleaned_value2, cleaned_value,
					ft_strlen(argv[j])) == 0)
			{
				ft_debug_printf("\nValue >%s< is a duplicate!\n\n", argv[j]);
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
	t_stack	*stack_a;

	ft_debug_printf("\n---------\nDEBUG ON!\n---------\n\n");
	if (check_args(argc, argv) == ft_true)
	{
		ft_debug_printf("\nInput arguments are fine...\n");
		stack_a = create_stack(argc, argv);
		if (!stack_a)
			return (1);
		print_stack(stack_a);
	}
	else
	{
		ft_printf("Error\n");
	}
	return (0);
}
