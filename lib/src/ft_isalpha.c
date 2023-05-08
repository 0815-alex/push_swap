/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:19 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:30:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

/**
 * @brief	This Function checks if 'c' is an alphabetic character 
 * 
 * @param 	c 
 * @return	int
 * 				1 = true
 * 				0 = false
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
