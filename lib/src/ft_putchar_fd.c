/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:41:05 by astein            #+#    #+#             */
/*   Updated: 2023/04/21 16:24:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief	Outputs the character 'c' to the given file descriptor 'fd'.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
