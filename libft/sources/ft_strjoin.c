/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:31:55 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:55:59 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	void	*t;
	size_t	s1_len;
	size_t	s2_len;

	if ((s1 == 0 && s2 == 0))
		return (NULL);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (new_str == 0)
		return (NULL);
	t = ft_memcpy(new_str, s1, s1_len);
	if (t == 0)
		return (NULL);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}
