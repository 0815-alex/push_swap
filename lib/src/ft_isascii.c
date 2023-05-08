/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:39:45 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:30:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

/**
 * @brief	This Functions checks whether 'c' is a 7-bit unsigned char value
 * 			that fits into the ASCII character set
 * 
 * @param 	c 
 * @return 	int
 * 				1 = true
 * 				0 = false
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
