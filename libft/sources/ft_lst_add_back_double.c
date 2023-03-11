/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_add_back_double.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:29:01 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:29:08 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lst_add_back_double(t_list **lst, t_list *new)
{
	if (lst == 0 || !new)
		return ;
	if (*lst && new)
	{
		ft_lstlast((*lst))->next = new;
		ft_lstlast((*lst))->next->prev = ft_lstlast((*lst));
	}
	else
	{
		*lst = new;
	}
}
