/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:20:51 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:20:58 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_dst_len(char *dst, size_t *dst_len, size_t dstsize)
{
	if (ft_strlen(dst) >= dstsize)
		*dst_len = dstsize;
	else
		*dst_len = ft_strlen(dst);
	return ;
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	set_dst_len(dst, &dst_len, dstsize);
	i = 0;
	if (dstsize == dst_len || dstsize == 0)
		return (dstsize + ft_strlen(src));
	if (ft_strlen(src) >= dstsize - dst_len)
	{
		while (i < dstsize - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	else
	{
		while (src[i] && i < dstsize - dst_len)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
