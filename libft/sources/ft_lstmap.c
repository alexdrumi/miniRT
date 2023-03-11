/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:45:41 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/27 13:45:44 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	new_lst = NULL;
	if (l && f && del)
	{
		while (l)
		{
			current = ft_lstnew((*f)(l->content));
			if (current == 0)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, current);
			l = l->next;
		}
	}
	return (new_lst);
}
