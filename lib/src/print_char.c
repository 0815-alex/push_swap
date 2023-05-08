/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:15:10 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:31:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

void	print_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}