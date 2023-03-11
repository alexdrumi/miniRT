/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	if (!content)
		return (NULL);
	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == 0)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0 || !new)
		return ;
	if (*lst && new)
	{
		ft_lstlast((*lst))->next = new;
	}
	else
	{
		*lst = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if ((lst && del))
	{
		(*del)(lst->content);
	}
	free(lst);
	return ;
}
