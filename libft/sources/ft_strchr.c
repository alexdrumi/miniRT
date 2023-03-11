/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:22:37 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:22:44 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	val;
	size_t			len;
	size_t			i;

	val = (unsigned char)c;
	len = ft_strlen(s) + 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == val)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
