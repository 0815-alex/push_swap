/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:50:07 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:31:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

void	print_ptr(unsigned long ptr, int *len)
{
	if (!ptr)
		print_str("(nil)", len);
	else
	{
		print_str("0x", len);
		print_dez_to_hexa(ptr, len, ft_false);
	}
}
