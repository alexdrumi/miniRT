/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include "../inc/structs.h"

t_bool		create_canvas(t_world *world, t_canvas *canvas,
				t_camera *camera);
t_color		**create_canvas_array(int width, int height);
t_canvas	*init_canvas(int width, int height);
void		fill_canvas(t_canvas *canvas);

#endif