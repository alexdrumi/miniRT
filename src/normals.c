/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/normals.h"
#include "../inc/vector_operations2.h"
#include "../inc/vector_operations1.h"
#include "../inc/object_normals.h"
#include "../inc/matrix_operations1.h"

void	world_to_object_space_local(t_comps *comps, t_ray_object *object,
	t_point3 *world_point)
{
	multiply_matrix44_point_to_point(object->inv_transform_mtx,
		world_point, &comps->local_point);
}

void	normal_to_world_tremo(t_ray_object *object, t_vector3 *local_normal)
{
	t_vector3	res;

	multiply_matrix44_vector_to_vector(object->transpose_inv_mtx,
		local_normal, &res);
	set_vector(local_normal, res.x, res.y, res.z);
	normalize(local_normal);
	local_normal->w = 0;
}

void	alt_normal_at(t_ray_object *object, t_point3 *world_point,
	t_intersection *hit, t_comps *comps)
{
	world_to_object_space_local(comps, object, world_point);
	(object->LOCAL_NORMAL_FUNCTION)(object, &comps->local_point,
		hit, &comps->normal);
	if (object->LOCAL_NORMAL_FUNCTION == cylinder_normal_tremo
		|| object->LOCAL_NORMAL_FUNCTION == plane_normal_tremo)
	{
		normal_to_world_tremo(object, &comps->normal);
	}
}
