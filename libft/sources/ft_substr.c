/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:31:20 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:31:26 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	if (s)
	{
		sub_s = (char *)malloc((len + 1) * sizeof(char));
		if (!sub_s)
			return (NULL);
		if (start >= ft_strlen(s))
		{
			sub_s[i] = '\0';
			return (sub_s);
		}
		while (s[start + i] && i < len)
		{
			sub_s[i] = s[start + i];
			i++;
		}
		sub_s[i] = '\0';
		return (sub_s);
	}
	return (NULL);
}
