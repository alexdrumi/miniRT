/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_operations1.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_OPERATIONS1_H
# define POINT_OPERATIONS1_H
# include "../inc/structs.h"

void	set_point(t_point3 *point, double x, double y, double z);
void	point_min_point(t_point3 *p1, t_point3 *p2, t_vector3 *res);
void	point_min_vector(t_point3 *p1, t_vector3 *v1, t_vector3 *res);
void	point_plus_vector(t_point3 *p1, t_vector3 *v1, t_vector3 *res);

#endif