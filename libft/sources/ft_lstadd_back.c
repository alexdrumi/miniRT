/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:45:41 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:46:57 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	write(1, "lst\n", 4);
	if (lst == 0)
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
