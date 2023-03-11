/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:24:10 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:24:16 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str) + 1;
	if (substr[0] == '\0')
		return ((char *)str);
	while (i < len && i < str_len)
	{
		j = 0;
		if (str[i] == substr[j])
		{
			while (substr[j] && i + j < len && str[i + j] == substr[j])
			{
				j++;
			}
			if (j == ft_strlen(substr))
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}
