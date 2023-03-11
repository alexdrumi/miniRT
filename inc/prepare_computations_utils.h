/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_computations.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPARE_COMPUTATIONS_UTILS_H
# define PREPARE_COMPUTATIONS_UTILS_H
# include "structs.h"

void	set_ray_origin(t_ray *ray, double x, double y, double z);
void	calc_refracted_vals(t_comps *comps);
void	calc_points(t_comps *comps);
void	calc_p_at_parameter(t_comps *comps, double t, t_ray *ray);

#endif