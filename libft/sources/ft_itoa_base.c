/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:29:01 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:29:08 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_string(long int n, int l, char *ptr, int base)
{
	static char	*char_selection = "0123456789abcdef";
	int			remainder;
	int			i;

	i = 0;
	remainder = 0;
	while (n)
	{
		remainder = (n % base);
		ptr[l - i - 1] = char_selection[remainder];
		n = n / base;
		i++;
	}
}

char	*ft_itoa_base(long int n, int base)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_digit_count(n, base);
	ptr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	if (n == 0)
		ptr[i] = '0';
	if (n < 0)
	{
		n = -n;
		ptr[i] = '-';
	}
	if (n)
		ft_create_string(n, len, ptr, base);
	return (ptr);
}
