/* ************************************************************************** */
/*                                                              */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:49 by astein            #+#    #+#             */
/*   Updated: 2023/04/21 10:58:43 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_ft_printf.h"

/**
 * @brief	Takes next arg from 'args' and a type identifier 'str' to call the
 * 			matching print_function.
 * 
 * @param	args	va_list with all the arguments
 * @param	str		type identifier (%cspdiuxX)	
 * @return	int		length of printed string
 */
static int	print_whatever(va_list args, char *str)
{
	int	len;

	len = 0;
	if (*str == '%')
		print_char('%', &len);
	else if (*str == 'c')
		print_char(va_arg(args, int), &len);
	else if (*str == 's')
		print_str(va_arg(args, char *), &len);
	else if (*str == 'p')
		print_ptr(va_arg(args, unsigned long), &len);
	else if (*str == 'd')
		print_nbr(va_arg(args, int), &len);
	else if (*str == 'i')
		print_nbr(va_arg(args, int), &len);
	else if (*str == 'u')
		print_nbr(va_arg(args, unsigned int), &len);
	else if (*str == 'x')
		print_dez_to_hexa(va_arg(args, unsigned int), &len, ft_false);
	else if (*str == 'X')
		print_dez_to_hexa(va_arg(args, unsigned int), &len, ft_true);
	return (len);
}

/**
 * @brief	This function prints the string 'str' while replacing the 
 * 			identifiers (%cspdiuxX) with values from va_list
 * 
 * @param 	str	string to be printed
 * @param 	... values to be printed
 * @return	int	length of printed string
 */
int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
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
	return (len);
}
