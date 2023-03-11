/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_computations_main.h                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPARE_COMPUTATIONS_MAIN_H
# define PREPARE_COMPUTATIONS_MAIN_H
# include "../inc/structs.h"

void	prepare_computations(t_intersection *intersect,
			t_intersections *intersect_list, t_ray *ray, t_world *world);

#endif