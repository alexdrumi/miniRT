/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/store_ambient.h"
#include "../inc/store_camera.h"
#include "../inc/store_lights.h"
#include "../inc/store_cylinder.h"
#include "../inc/store_plane.h"
#include "../inc/store_sphere.h"
#include "../inc/pixel_operations.h"
#include "../inc/get_next_line.h"
#include "../inc/general_utils.h"
#include "../inc/parse_utils.h"
#include "../inc/parse1.h"

static void	set_cam_res(t_minirt *minirt)
{
	t_camera	*cam;
	t_list		*cam_list;

	cam_list = (void *)minirt->cam_list;
	while (cam_list != NULL)
	{
		cam = (t_camera *)cam_list->content;
		cam->h_size = minirt->res_width;
		cam->v_size = minirt->res_height;
		cam->aspect_ratio = (double)minirt->res_width
			/ (double)minirt->res_height;
		set_pixel_size(cam);
		cam_list = cam_list->next;
	}	
}

static t_bool	is_filename_correct(char *name)
{
	size_t	i;

	i = ft_strlen((const char *)name);
	if (i < 3)
		return (false);
	if ((name[i - 3] == '.' && (name[i - 2] == 'r') && name[i - 1] == 't'))
		return (true);
	else
		return (false);
}

static t_bool	select_storing_function(t_minirt *minirt, char *line,
					char *data, char *split_cont)
{
	t_bool	succeeded;

	succeeded = true;
	if (ft_strncmp(line, "A", 1) == 0 && is_whitespace(*(line + 1)))
		succeeded = store_ambient(minirt, line, &data, &split_cont);
	else if (ft_strncmp(line, "C", 1) == 0 && is_whitespace(*(line + 1)))
		succeeded = store_camera(minirt, line, &data, &split_cont);
	else if (ft_strncmp(line, "L", 1) == 0 && is_whitespace(*(line + 1)))
		succeeded = store_lights(minirt, line, &data, &split_cont);
	else if (ft_strncmp(line, "sp", 2) == 0 && is_whitespace(*(line + 2)))
		succeeded = store_sphere(minirt, line, &data);
	else if (ft_strncmp(line, "pl", 2) == 0 && is_whitespace(*(line + 2)))
		succeeded = store_plane(minirt, line, &data);
	else if (ft_strncmp(line, "cy", 2) == 0 && is_whitespace(*(line + 2)))
		succeeded = store_cylinder(minirt, line, &data);
	else if (is_line_empty(line) == false)
		succeeded = false;
	return (succeeded);
}

static t_bool	parse_lines(t_minirt *minirt, int fd)
{
	char	*line;
	char	*data;
	char	*split_cont;
	int		ret;
	t_bool	succeeded;

	line = 0;
	data = 0;
	split_cont = 0;
	ret = 1;
	succeeded = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (false);
		succeeded = select_storing_function(minirt, line,
				data, split_cont);
		free(line);
		if (succeeded == false)
		{
			return (false);
		}
	}
	return (true);
}

t_bool	parse_rt_file(char *rt_file, t_minirt *minirt)
{
	int			fd;

	if (is_filename_correct(rt_file) == false)
		return (false);
	fd = open(rt_file, O_RDONLY);
	if (fd < 0)
		return (false);
	if (parse_lines(minirt, fd) == false)
	{
		close(fd);
		return (false);
	}
	close(fd);
	if ((minirt->bitflags & (1 << 4)) > 0)
		set_cam_res(minirt);
	if ((minirt->bitflags & (1 << 1)) == 0)
	{
		set_color(&minirt->world.ambient_col, 0, 0, 0);
		minirt->ambient = 0;
	}
	if ((minirt->bitflags & (1 << 8)) == 0)
		return (false);
	return (true);
}
