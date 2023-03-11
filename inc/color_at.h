/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_at.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_AT_H
# define COLOR_AT_H
# include "../inc/structs.h"

t_color			*color_at(t_world *world, t_ray *ray, int remaining);
t_intersection	*hit_object(t_intersections *list);

#endif