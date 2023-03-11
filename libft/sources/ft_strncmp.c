/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:24:55 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:25:02 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (!n)
		return (0);
	i = 0;
	if (ft_strlen(s1) < ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	while (i < len && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
