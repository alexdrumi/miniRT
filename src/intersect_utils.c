/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection_functions_utils.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersect_utils.h"
#include "../inc/point_operations1.h"
#include "../inc/matrix_operations1.h"
#include <math.h>

void	swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	check_and_swap_xs_vals(double xs[2])
{
	if (xs[0] > xs[1])
		swap_double(&xs[0], &xs[1]);
	if (xs[0] < 0)
	{
		xs[0] = xs[1];
		if (xs[0] < 0)
			return (0);
	}
	return (1);
}

int	solve_quadratic(double abc[3], double t[2])
{
	double	discriminant;
	double	q;

	discriminant = pow(abc[1], 2) - (4 * abc[0] * abc[2]);
	if (discriminant < 0)
		return (0);
	else if (discriminant == 0)
	{
		t[0] = -0.5 * abc[1] / abc[0];
		t[1] = -0.5 * abc[1] / abc[0];
	}
	else
	{
		if ((abc[1] > 0))
		{
			q = (-0.5 * (abc[1] + sqrt(discriminant)));
		}
		else
		{
			q = (-0.5 * (abc[1] - sqrt(discriminant)));
		}
		t[0] = q / abc[0];
		t[1] = abc[2] / q;
	}
	return (1);
}

void	ray_to_object_space_local(t_ray_object *object, t_ray *ray,
			t_ray *res_ray)
{
	if (!object || !ray || !res_ray)
		return ;
	multiply_matrix44_point_to_point(object->inv_transform_mtx,
		&ray->orig, &res_ray->orig);
	multiply_matrix44_vector_to_vector(object->inv_transform_mtx,
		&ray->dir, &res_ray->dir);
}
