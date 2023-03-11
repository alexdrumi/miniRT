/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_cylinder.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_CYLINDER_H
# define STORE_CYLINDER_H
# include "../inc/structs.h"

t_bool	store_cylinder(t_minirt *minirt, char *line, char **data);
t_bool	get_geometry_data(char **data, t_ray_object *obj,
			int index, double *geom_attribute);

#endif