/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_n_in_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:45:41 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/27 13:45:44 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_is_n_in_str(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
