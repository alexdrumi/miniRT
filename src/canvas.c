/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/canvas.h"
#include "../inc/pixel_operations.h"
#include "../inc/color_at.h"
#include "../inc/prepare_computations_utils.h"
#include "../inc/general_utils2.h"
#include "../inc/general_utils3.h"
#include "../inc/destroy1.h"
#include "../inc/destroy2.h"
#include "../inc/destroy4.h"
#include "../libft/headers/libft.h"

t_bool	create_canvas(t_world *world, t_canvas *canvas,
						t_camera *camera)
{
	int			y;
	int			x;
	//int			samples_per_pixel;
	t_color			*current_color;

	y = 0;
	//samples_per_pixel = 100;
	while (y < camera->v_size)
	{
		x = 0;
		while (x < camera->h_size)
		{
			set_ray_through_pixel(world, camera, x, y);
			current_color = color_at(world, &world->ray_through_pixel, 5);
			if (!current_color)
				print_malloc_error_and_exit();
			write_pixel(canvas, x, y, current_color);
			free(current_color);
			set_color(&world->final_col.surface, 0, 0, 0);
			x++;
		}
		y++;
	}
	return (true);
}

void	fill_canvas(t_canvas *canvas)
{
	t_color	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = (t_color *)(canvas->pixels + canvas->height);
	while (i < canvas->height)
	{
		canvas->pixels[i] = (ptr + canvas->width * i);
		i++;
	}
	i = 0;
	while (i < canvas->height)
	{
		j = 0;
		while (j < canvas->width)
		{
			canvas->pixels[i][j].r = 0;
			canvas->pixels[i][j].g = 0;
			canvas->pixels[i][j].b = 0;
			j++;
		}
		i++;
	}
}

t_color	**create_canvas_array(int width, int height)
{
	int		len;
	t_color	**arr;

	len = sizeof(t_color *) * height + sizeof(t_color) * width * height;
	arr = (t_color **)malloc(len);
	if (!arr)
		print_malloc_error_and_exit();
	return (arr);
}

t_canvas	*init_canvas(int width, int height)
{
	t_canvas	*new_canvas;

	new_canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!new_canvas)
		print_malloc_error_and_exit();
	new_canvas->width = width;
	new_canvas->height = height;
	new_canvas->pixels = create_canvas_array(width, height);
	return (new_canvas);
}
