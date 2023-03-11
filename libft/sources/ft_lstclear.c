/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:45:41 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:48:30 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if ((lst && *lst && del))
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, (*del));
			*lst = tmp;
		}
	}
	return ;
}
