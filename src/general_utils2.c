/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general_utils2.h"
#include "../inc/ft_fatoi.h"

static int	check_max_rgb(double r, double g, double b)
{
	return ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255));
}

static int	check_normalized(double a, double b, double c)
{
	return ((a >= -1 && a <= 1) && (b >= -1 && b <= 1) && (c >= -1 && c <= 1));
}

int	check_fatoi_error(double a, double b, double c)
{
	return (a == FATOI_ERROR || b == FATOI_ERROR || c == FATOI_ERROR);
}

void	set_color(t_color *color, double r, double g, double b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

t_bool	check_components(char **components, double *return_values,
	t_minirt *minirt)
{
	double	a;
	double	b;
	double	c;

	a = ft_fatoi(components[0]);
	b = ft_fatoi(components[1]);
	c = ft_fatoi(components[2]);
	if ((minirt->bitflags & (1 << 2)) > 0)
	{
		minirt->bitflags &= ~(1 << 2);
		if (check_max_rgb(a, b, c))
			return (false);
	}
	if ((minirt->bitflags & (1 << 3)) > 0)
	{
		minirt->bitflags &= ~(1 << 3);
		if (!check_normalized(a, b, c) || check_fatoi_error(a, b, c))
			return (false);
	}
	if (check_fatoi_error(a, b, c))
		return (false);
	return_values[0] = a;
	return_values[1] = b;
	return_values[2] = c;
	return (true);
}
