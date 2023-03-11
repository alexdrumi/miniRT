/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:16:08 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:50:33 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == val)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
