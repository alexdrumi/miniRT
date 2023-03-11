/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/store_camera.h"
#include "../inc/init_functions4.h"
#include "../inc/ft_fatoi.h"
#include "../inc/general_utils3.h"
#include "../inc/general_utils.h"
#include "../inc/destroy4.h"

static t_bool	check_input(t_minirt *minirt, char **data,
			char **split_cont, double cam_view_coords[3])
{
	char	**data1;

	(void)split_cont;
	if (check_correct_nr_of_inputs(data, 4) == false)
	{
		return (false);
	}
	data1 = ft_split(data[1], ',');
	if (check_correct_nr_of_inputs(data1, 3) == false)
	{
		return (free_chararr_return_false(data1));
	}
	if (check_components(data1, cam_view_coords,
			minirt) == false)
	{
		return (free_chararr_return_false(data1));
	}
	free_split_array(data1);
	return (true);
}

static t_bool	check_rest(t_minirt *minirt, char **split_cont,
	double cam_orient_coords[3])
{
	// int	a;
	// int	b;
	// int	c;

	// a = ft_fatoi(split_cont[0]);
	// b = ft_fatoi(split_cont[1]);
	// c = ft_fatoi(split_cont[2]);
	if (check_correct_nr_of_inputs(split_cont, 3) == false)
		return (free_splitted_return_false((void **)split_cont));
	minirt->bitflags |= (1 << 3);
	if (check_components(split_cont, cam_orient_coords,
			minirt) == false)
		return (free_splitted_return_false((void **)split_cont));
	free_split_array(split_cont);
	return (true);
}

t_bool	store_camera(t_minirt *minirt, char *line, char **data,
			char **split_cont)
{
	double	cam_view_coords[3];
	double	cam_orient_coords[3];
	char	**local_data;
	double	fov;

	(void)data;
	if ((minirt->bitflags & (1 << 8)) > 0)
		return (false);
	local_data = ft_split_whitespace(line);
	if (!local_data)
		return (false);
	if (check_input(minirt, local_data, split_cont, cam_view_coords) == false)
		return (free_chararr_return_false(local_data));
	split_cont = ft_split(local_data[2], ',');
	if (!split_cont)
		return (free_splitted_return_false((void **)local_data));
	fov = ft_fatoi(local_data[3]);
	if (fov == FATOI_ERROR || fov < 0 || fov > 180)
		return (false);
	if (!check_rest(minirt, split_cont, cam_orient_coords))
		return (free_splitted_return_false((void **)local_data));
	free_split_array_void((void **)local_data);
	return (create_camera(cam_view_coords, cam_orient_coords,
			fov, minirt));
}
