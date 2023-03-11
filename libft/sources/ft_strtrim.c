/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:32:29 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:32:36 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s;
	size_t	len;
	size_t	start;

	if (s1 == 0 || set == 0)
		return (NULL);
	trimmed_s = NULL;
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	while (s1[len - 1] && char_in_set(s1[len - 1], set))
		len--;
	if (len == 0)
		len = start;
	if (len >= start)
	{
		trimmed_s = (char *)ft_calloc((len - start + 1), sizeof(char));
		if (trimmed_s == 0)
			return (NULL);
		ft_strlcpy(trimmed_s, &s1[start], (len - start + 1));
	}
	return (trimmed_s);
}
