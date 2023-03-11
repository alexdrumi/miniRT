/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_normals.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/object_normals.h"
#include "../inc/vector_operations2.h"
#include "../inc/vector_operations1.h"
#include "../inc/point_operations1.h"
#include "../inc/macros.h"
#include <math.h>

void	cylinder_normal_tremo(t_ray_object *cylinder, t_point3 *local_point,
			void *hit, t_vector3 *local_normal)
{
	double	distance;

	(void)hit;
	distance = pow(local_point->x, 2) + pow(local_point->z, 2);
	if (distance < 1 && local_point->y >= cylinder->maximum - EPSILON)
		set_vector(local_normal, 0, 1, 0);
	else if (distance < 1 && local_point->y <= cylinder->minimum + EPSILON)
		set_vector(local_normal, 0, -1, 0);
	else
		set_vector(local_normal, local_point->x, 0, local_point->z);
}

void	plane_normal_tremo(t_ray_object *plane, t_point3 *local_point,
			void *hit, t_vector3 *local_normal)
{
	(void)plane;
	(void)hit;
	(void)local_point;
	set_vector(local_normal, 0, 1, 0);
}

void	square_normal_tremo(t_ray_object *square, t_point3 *local_point,
			void *hit, t_vector3 *local_normal)
{
	(void)square;
	(void)hit;
	(void)local_point;
	set_vector(local_normal, 0, 1, 0);
}

void	sphere_normal_tremo(t_ray_object *sphere, t_point3 *local_point,
			void *hit, t_vector3 *local_normal)
{
	t_point3	origin;

	(void)sphere;
	(void)hit;
	(void)local_point;
	set_point(&origin, 0, 0, 0);
	point_min_point(local_point, &origin, local_normal);
	normalize(local_normal);
	local_normal->w = 0;
}
