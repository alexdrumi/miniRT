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

#ifndef INIT_FUNCTIONS1_H
# define INIT_FUNCTIONS1_H
# include "../inc/structs.h"

t_point3		*init_point(double x, double y, double z);
t_vector3		*init_vector(double x, double y, double z);
t_ray			*init_ray(t_point3 *origin, t_vector3 *direction);
t_intersection	*init_intersect(t_ray_object *object,
					double t_val, double u, double v);
#endif