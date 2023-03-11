/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:30:03 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:45:43 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	total_bytes;

	total_bytes = count * size;
	ret = malloc(total_bytes);
	if (ret == 0)
		return (NULL);
	ft_bzero(ret, (total_bytes));
	return (ret);
}
