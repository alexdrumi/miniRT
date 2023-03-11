/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:34:14 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:34:21 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_string(long long int n, size_t l, size_t i, char *ptr)
{
	while (n)
	{
		ptr[l - i - 1] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	ptr[l] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long long int	number;
	char			*ptr;
	size_t			i;
	size_t			len;

	number = n;
	len = ft_digit_count(number, 10);
	ptr = (char *)ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (number == 0)
		ptr[i] = '0';
	if (number < 0)
	{
		number = -number;
		ptr[i] = '-';
	}
	if (number)
		return (create_string(number, len, i, ptr));
	return (ptr);
}
