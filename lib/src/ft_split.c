/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:24:38 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 15:38:12 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_printf.h"

/**
 * @brief	Counts how many parts (words) result from splitting String 's' using
 * 			the delimiter 'c'. Empty substrings will not be counted!
 * 
 * @param	s	
 * @param	c 
 * @return	int Number of words in 's'
 */
static int	cnt_wrds(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

/**
 * @brief	This function searches for char 'c' in String 's' and returns the
 * 			position of 'c' in 's'
 */
int	wrdlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/**
 * @brief	Allocates and returns an array of strings obtained by splitting 's'
 * 			using the character 'c' as a delimiter.
 * 			The array ends with a NULL pointer.
 * 
 * @param	s	The string to be split.
 * @param 	c 	The delimiter character.
 * @return 	char**
 * 				The array of new strings resulting from the split.
 * 				NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	w = cnt_wrds(s, c);
	res = malloc(sizeof(char *) * (w + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < w)
	{
		while (*s == c && *s != '\0')
			s++;
		len = wrdlen(s, c);
		res[i] = ft_substr(s, 0, len);
		if (!res[i])
			return (NULL);
		s += len;
		i++;
	}
	res[w] = NULL;
	return (res);
}
