/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"
#include "../minilibx/mlx.h"
#include "../inc/canvas.h"
#include "../inc/pixel_operations.h"
#include "../inc/parse_utils.h"
#include "../inc/destroy4.h"
#include "../inc/destroy1.h"
#include "../inc/destroy2.h"
#include "../inc/general_utils3.h"
#include <math.h>

double	clamp(double low, double high, double value)
{
	return (fmax(low, fmin(high, value)));
}

void	display_to_mlx(t_canvas *canvas, t_camera *camera, t_minirt *minirt)
{
	int	y;
	int	x;
	int	color;

	camera->image_ptr.img = mlx_new_image(minirt->mlx,
			camera->h_size, camera->v_size);
	camera->image_ptr.addr = mlx_get_data_addr(camera->image_ptr.img,
			&camera->image_ptr.bits_per_pixel,
			&camera->image_ptr.line_length, &camera->image_ptr.endian);
	y = 0;
	while (y < camera->v_size)
	{
		x = 0;
		while (x < camera->h_size)
		{
			color = create_trgb(0,
					(int)(255 * clamp(0, 1, canvas->pixels[y][x].r)),
					(int)(255 * clamp(0, 1, canvas->pixels[y][x].g)),
					(int)(255 * clamp(0, 1, canvas->pixels[y][x].b)));
			my_mlx_pixel_put(&camera->image_ptr, x, y, color);
			x++;
		}
		y++;
	}
	return ;
}

void	render(t_world *world, t_camera *camera, t_minirt *minirt)
{
	t_canvas	*canvas;

	canvas = init_canvas(camera->h_size, camera->v_size);
	if (!canvas)
	{
		print_malloc_error_and_exit();
	}
	fill_canvas(canvas);
	if (create_canvas(world, canvas, camera) == false)
	{
		print_malloc_error_and_exit();
	}
	display_to_mlx(canvas, camera, minirt);
	free(canvas->pixels);
	free(canvas);
	return ;
}

void	render_all_cameras(t_minirt *minirt)
{
	t_camera	*current_cam;
	t_list		*cam_list;

	cam_list = (void *)minirt->cam_list;
	while (cam_list != NULL)
	{
		current_cam = (t_camera *)cam_list->content;
		render(&minirt->world, current_cam, minirt);
		destroy_matrix(current_cam->inv_transf_matrix, 4);
		destroy_matrix(current_cam->transform_matrix, 4);
		cam_list = cam_list->next;
	}
	ft_lstclear(&minirt->world.object_list, &destroy_ray_obj);
	free(minirt->world.object_list);
	ft_lstclear(&minirt->world.light_list, &destroy_pointlight);
	free(minirt->world.light_list);
	return ;
}
