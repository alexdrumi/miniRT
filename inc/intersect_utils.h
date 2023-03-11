/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_UTILS_H
# define INTERSECT_UTILS_H

# include "structs.h"

void	ray_to_object_space_local(t_ray_object *object, t_ray *ray,
			t_ray *res_ray);
int		solve_quadratic(double abc[3], double t[2]);
int		check_and_swap_xs_vals(double xs[2]);
void	swap_double(double *a, double *b);

#endif
