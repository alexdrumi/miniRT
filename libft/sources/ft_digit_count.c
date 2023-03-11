/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_count.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:29:01 by bmajor        #+#    #+#                 */
/*   Updated: 2020/10/31 07:29:08 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_digit_count(long int n, int base)
{
	int		len;

	len = 0;
	if (n == 0 || n < 0)
		len++;
	if (n < 0)
		n = -n;
	while (n)
	{
		len++;
		n = n / base;
	}
	return (len);
}
