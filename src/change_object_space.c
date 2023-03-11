/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_object_space.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/matrix_operations1.h"
#include "../inc/change_object_space.h"

t_point3	*world_to_object_space(t_ray_object *object, t_point3 *world_point)
{
	return (multiply_matrix44_point(object->inv_transform_mtx,
			world_point));
}
