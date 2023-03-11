/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersect_cylinder.h"
#include "../inc/intersect_utils.h"
#include "../inc/intersections.h"
#include "../inc/init_functions1.h"
#include "../inc/point_operations1.h"
#include "../inc/macros.h"
#include <math.h>

static int	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->orig.x + (t * ray->dir.x);
	z = ray->orig.z + (t * ray->dir.z);
	return (pow(x, 2) + pow(z, 2) <= 1);
}

static void	intersect_caps(t_ray_object *cyl, t_ray *ray, t_intersections *list)
{
	double	t;

	if (cyl->closed == 0 && (ray->dir.y >= 0 && ray->dir.y <= EPSILON))
		return ;
	t = (cyl->minimum - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t))
		add_to_intersect_list(list, init_intersect(cyl, t, 0, 0));
	t = (cyl->maximum - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t))
		add_to_intersect_list(list, init_intersect(cyl, t, 0, 0));
}

static void	assign_cyl_intersects(t_ray_object *obj, double xs[2],
				t_intersections *list)
{
	double		y[2];

	y[0] = obj->local_ray.orig.y + xs[0] * obj->local_ray.dir.y;
	if (obj->minimum < y[0] && y[0] < obj->maximum)
		add_to_intersect_list((t_intersections *)list,
			init_intersect(obj, xs[0], 0, 0));
	y[1] = obj->local_ray.orig.y + xs[1] * obj->local_ray.dir.y;
	if (obj->minimum < y[1] && y[1] < obj->maximum)
		add_to_intersect_list((t_intersections *)list,
			init_intersect(obj, xs[1], 0, 0));
	if (obj->closed == 1)
		intersect_caps(obj, &obj->local_ray, (t_intersections *)list);
}

void	intersect_cylinder(t_ray_object *obj, t_ray *ray, void *list)
{
	double		abc[3];
	double		xs[2];
	t_vector3	sphere_to_ray;
	t_point3	origin;

	ray_to_object_space_local(obj, ray, &obj->local_ray);
	set_point(&origin, 0, 0, 0);
	point_min_point(&obj->local_ray.orig, &origin, &sphere_to_ray);
	abc[0] = pow(obj->local_ray.dir.x, 2) + pow(obj->local_ray.dir.z, 2);
	if (abc[0] >= 0 && abc[0] <= EPSILON && obj->closed == 1)
	{
		intersect_caps(obj, &obj->local_ray, (t_intersections *)list);
		return ;
	}
	abc[1] = (2 * obj->local_ray.orig.x * obj->local_ray.dir.x)
		+ (2 * obj->local_ray.orig.z * obj->local_ray.dir.z);
	abc[2] = pow(obj->local_ray.orig.x, 2)
		+ pow(obj->local_ray.orig.z, 2) - 1;
	if (solve_quadratic(abc, xs) == 0)
		return ;
	if (check_and_swap_xs_vals(xs) == 0)
		return ;
	assign_cyl_intersects(obj, xs, list);
}
