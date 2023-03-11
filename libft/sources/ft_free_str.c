/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:33:10 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 20:29:28 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_str(char **str, size_t index)
{
	while (index > 0)
	{
		free(str[index - 1]);
		index--;
	}
	free(str);
	return (0);
}
