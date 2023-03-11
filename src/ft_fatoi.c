/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fatoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fatoi.h"
#include <math.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static void	skip_space_and_sign(const char *str, int *i, double *j,
	double *sign)
{
	*sign = 1;
	*i = 0;
	*j = 0;
	while (str[*i] != '\0' && ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			*sign = -(*sign);
		(*i)++;
	}
}

static int	calc_float_part(const char *str, int *decimal_flag,
				double *j, double *res)
{
	if ((*decimal_flag == 1 && *str == '.')
		|| (*str == '.' && !ft_isdigit(*(str - 1))))
		return (-1);
	else if (*j == 0)
	{	
		*decimal_flag = 1;
		*j = 1;
	}
	else
	{
		*res = *res + (*str - '0') / (pow(10, *j));
		(*j)++;
	}	
	return (1);
}

double	ft_fatoi(const char *str)
{
	int		decimal_flag;
	int		i;
	double	j;
	double	sign;
	double	res;

	res = 0;
	decimal_flag = 0;
	if (!str)
		return (FATOI_ERROR);
	skip_space_and_sign(str, &i, &j, &sign);
	if (ft_isdigit(str[i]) == 0)
		return (FATOI_ERROR);
	while ((str[i] != '\0' && ft_isdigit(str[i])) || str[i] == '.')
	{
		if (str[i] != '.' && decimal_flag == 0)
			res = res * 10 + (str[i] - '0');
		else
			if (calc_float_part((str + i), &decimal_flag, &j, &res) == -1)
				return (FATOI_ERROR);
		i++;
	}
	if (str[i] != '\0' || (res == 0 && sign == -1))
		return (FATOI_ERROR);
	return (res * sign);
}
