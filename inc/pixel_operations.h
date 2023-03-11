/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_operations.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_OPERATIONS_H
# define PIXEL_OPERATIONS_H
# include "structs.h"
# include "point_operations1.h"
# include "vector_operations1.h"
# include "matrix_operations1.h"

void	set_ray_through_pixel(t_world *world, t_camera *cam,
			double x, double y);
void	write_pixel(t_canvas *canvas, int column, int row, t_color *color);
void	set_pixel_size(t_camera *cam);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
