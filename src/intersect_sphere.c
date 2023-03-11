/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersect_sphere.h"
#include "../inc/intersect_utils.h"
#include "../inc/intersections.h"
#include "../inc/init_functions1.h"
#include "../inc/point_operations1.h"
#include "../inc/vector_operations2.h"

void	intersect_sphere(t_ray_object *obj, t_ray *ray, void *list)
{
	double		abc[3];
	double		xs[2];
	t_vector3	sphere_to_ray;
	t_point3	origin;

	ray_to_object_space_local(obj, ray, &obj->local_ray);
	set_point(&origin, 0, 0, 0);
	point_min_point(&obj->local_ray.orig, &origin, &sphere_to_ray);
	abc[0] = get_dot_prod(&obj->local_ray.dir, &obj->local_ray.dir);
	abc[1] = 2 * get_dot_prod(&obj->local_ray.dir, &sphere_to_ray);
	abc[2] = get_dot_prod(&sphere_to_ray, &sphere_to_ray) - 1;
	if (solve_quadratic(abc, xs) == 0)
		return ;
	if (check_and_swap_xs_vals(xs) == 0)
		return ;
	add_to_intersect_list((t_intersections *)list,
		init_intersect(obj, xs[0], 0, 0));
	add_to_intersect_list((t_intersections *)list,
		init_intersect(obj, xs[1], 0, 0));
	return ;
}
