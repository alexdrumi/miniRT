/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:23:08 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:23:16 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	val;
	size_t			len;

	val = (unsigned char)c;
	len = ft_strlen(s) + 1;
	while (len)
	{
		if (s[len - 1] == val)
		{
			return ((char *)&s[len - 1]);
		}
		len--;
	}
	return (NULL);
}
