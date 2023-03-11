/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:45:41 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/27 13:45:44 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if ((dst && src) == 0)
		return ;
	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
}
