/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pixel_operations.h"
#include "../inc/vector_operations2.h"

void	set_ray_through_pixel(t_world *world, t_camera *cam, double x, double y)
{
	t_point3	pixel;
	t_point3	origin;
	t_point3	world_p;
	t_point3	zero;
	t_vector3	dir;

	set_point(&world_p, cam->half_width - (x + 0.5) * cam->pixel_size,
		cam->half_height - (y + 0.5) * cam->pixel_size,
		-1);
	set_point(&zero, 0, 0, 0);
	multiply_matrix44_point_to_point(cam->inv_transf_matrix, &world_p, &pixel);
	multiply_matrix44_point_to_point(cam->inv_transf_matrix, &zero, &origin);
	point_min_point(&pixel, &origin, &dir);
	normalize(&dir);
	set_point(&world->ray_through_pixel.orig, origin.x, origin.y, origin.z);
	set_vector(&world->ray_through_pixel.dir, dir.x, dir.y, dir.z);
}

void	write_pixel(t_canvas *canvas, int column, int row, t_color *color)
{
	canvas->pixels[row][column].r = color->r;
	canvas->pixels[row][column].g = color->g;
	canvas->pixels[row][column].b = color->b;
}

void	set_pixel_size(t_camera *cam)
{
	if (cam->aspect_ratio >= 1)
	{
		cam->half_width = cam->half_fov;
		cam->half_height = cam->half_fov / cam->aspect_ratio;
	}
	else
	{
		cam->half_width = cam->half_fov * cam->aspect_ratio;
		cam->half_height = cam->half_fov;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->h_size;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}
