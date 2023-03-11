/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_normals.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_NORMALS_H
# define OBJECT_NORMALS_H
# include "../inc/structs.h"

void	cylinder_normal_tremo(t_ray_object *cylinder, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);
void	square_normal_tremo(t_ray_object *square, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);
void	plane_normal_tremo(t_ray_object *plane, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);
void	sphere_normal_tremo(t_ray_object *sphere, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);
void	cube_normal_tremo(t_ray_object *cube, t_point3 *local_point,
			void *hit, t_vector3 *local_normal);

#endif