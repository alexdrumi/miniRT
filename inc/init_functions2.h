/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions1.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FUNCTIONS2_H
# define INIT_FUNCTIONS2_H
# include "../inc/structs.h"

t_pointlight	*init_point_light(t_point3 *pos, t_color *intensity);
t_camera		*init_cam(double hsize, double vsize, double horizontal_fov);
t_ray_object	*init_ray_object(int type,
					void (*intersect_function_ptr)
					(t_ray_object *, t_ray *, void *),
					void (*local_normal_function_ptr)
					(t_ray_object *, t_point3 *, void *, t_vector3 *));
void			init_mat(t_mat *new_mat);

#endif