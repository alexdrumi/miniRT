/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersections.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "structs.h"

t_intersections	*intersect_world(t_world *world, t_ray *ray);
void			add_to_intersect_list(t_intersections *list,
					t_intersection *object);
void			free_intersect_list(t_intersections *list);

#endif
