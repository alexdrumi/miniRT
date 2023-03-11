/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:17:54 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:18:02 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	val;
	unsigned char	*s_ptr;
	size_t			i;

	val = (unsigned char)c;
	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == val)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
