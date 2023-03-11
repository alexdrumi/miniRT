/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_object_space.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE_OBJECT_SPACE_H
# define CHANGE_OBJECT_SPACE_H
# include "../inc/structs.h"

t_point3	*world_to_object_space(t_ray_object *object, t_point3 *world_point);

#endif