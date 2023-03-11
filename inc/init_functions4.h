/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cam.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FUNCTIONS4_H
# define INIT_FUNCTIONS4_H
# include "../inc/structs.h"

t_bool			create_camera(double cam_view_coords[3],
					double cam_orient_coords[3], double fov, t_minirt *minirt);

#endif