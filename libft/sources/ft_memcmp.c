/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:18:46 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:18:57 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	if (!n)
		return (0);
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n - 1)
	{
		if (s1_ptr[i] != s2_ptr[i])
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
}
