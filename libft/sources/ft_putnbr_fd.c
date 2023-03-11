/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:38:02 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:38:09 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(long long int num, int fd)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', fd);
	}
	else
	{
		recursive(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	recursive(num, fd);
}
