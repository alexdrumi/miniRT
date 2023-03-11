/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersect_plane.h"
#include "../inc/intersect_utils.h"
#include "../inc/intersections.h"
#include "../inc/init_functions1.h"
#include "../inc/macros.h"
#include <math.h>

void	intersect_plane(t_ray_object *obj, t_ray *ray, void *list)
{
	double	res;

	ray_to_object_space_local(obj, ray, &obj->local_ray);
	if (fabs(obj->local_ray.dir.y) < EPSILON)
		return ;
	res = (obj->local_ray.orig.y * -1) / obj->local_ray.dir.y;
	add_to_intersect_list((t_intersections *)list,
		init_intersect(obj, res, 0, 0));
}
