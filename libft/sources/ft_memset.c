/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:14:03 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 19:52:53 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *mem_loc, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*s;
	size_t			i;

	val = (unsigned char)c;
	s = (unsigned char *)mem_loc;
	i = 0;
	while (i < len)
	{
		s[i] = val;
		i++;
	}
	return (mem_loc);
}
