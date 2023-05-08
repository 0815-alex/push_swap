/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:14:42 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:31:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

void	print_str(char *str, int *len)
{
	if (!str)
		print_str("(null)", len);
	else
	{
		while (*str)
		{
			print_char(*str, len);
			str++;
		}
	}
}
