/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:11:23 by astein            #+#    #+#             */
/*   Updated: 2023/04/21 16:24:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief	Deletes and frees the given node and every successor of that node,
 * 			using the function 'del' and 'ft_lstdelone'.
 * 			Finally, the pointer to the list is set to NULL.
 * 
 * @param lst	The address of a pointer to a node.
 * @param del	The address of a function used to delete the content of the node
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
