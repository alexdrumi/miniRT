/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions5.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FUNCTIONS5_H
# define INIT_FUNCTIONS5_H
# include "structs.h"

t_camera		*init_cam(double hsize, double vsize, double horizontal_fov);
void			init_comps(t_world *world);
void			init_is_shadowed(t_shade_hit	*new_shade_hit);
#endif