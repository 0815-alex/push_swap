/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:59:52 by astein            #+#    #+#             */
/*   Updated: 2023/05/08 23:30:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

/**
 * @brief	This Function checks if 'c' is an alphanumeric character
 * 
 * @param 	c 
 * @return	int
 * 				1 = true
 * 				0 = false
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
