/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALS_H
# define NORMALS_H
# include "structs.h"

void	normal_to_world_tremo(t_ray_object *object, t_vector3 *local_normal);
void	alt_normal_at(t_ray_object *object, t_point3 *world_point,
			t_intersection *hit, t_comps *comps);
void	world_to_object_space_local(t_comps *comps, t_ray_object *object,
			t_point3 *world_point);
void	triangle_normal_tremo(t_ray_object *triangle, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);
#endif
