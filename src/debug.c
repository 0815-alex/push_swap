/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:44:25 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 01:25:30 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_debug_printf(char *str, ...)
{
	va_list	args;
	int		len;

	if (DEBUG == 1)
	{
		va_start(args, str);
		len = 0;
		while (*str)
		{
			if (*str == '%')
			{
				str++;
				len += print_whatever(args, (char *)str);
			}
			else
				print_char(*str, &len);
			str++;
		}
		va_end(args);
	}
}
