/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_triangle.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/11/20 14:23:52 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_PLANE_H
# define INTERSECT_PLANE_H
# include "structs.h"

void		intersect_plane(t_ray_object *obj, t_ray *ray, void *list);

#endif
