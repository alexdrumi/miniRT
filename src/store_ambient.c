/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/store_ambient.h"
#include "../inc/general_utils.h"
#include "../inc/general_utils3.h"
#include "../inc/ft_fatoi.h"

static t_bool	is_ambient_ratio_in_range(double *amb_comps)
{
	if (amb_comps[3] > 1 || amb_comps[3] < 0)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

static t_bool	check_rest(t_minirt *minirt, char **split_rgb, char **data_loc,
	double amb_comps[4])
{
	if (check_correct_nr_of_inputs(split_rgb, 3) == false)
	{
		free_split_array(split_rgb);
		free_split_array(data_loc);
		return (false);
	}
	minirt->bitflags |= (1 << 2);
	if (check_components(split_rgb, amb_comps, minirt) == false)
	{
		free_split_array(data_loc);
		free_split_array(split_rgb);
		return (false);
	}
	set_color(&minirt->ambient_col, amb_comps[0] / 255,
		amb_comps[1] / 255, amb_comps[2] / 255);
	minirt->world.ambient_col = minirt->ambient_col;
	minirt->ambient = amb_comps[3];
	minirt->bitflags |= (1 << 1);
	if (data_loc)
		free_split_array(data_loc);
	free_split_array(split_rgb);
	return (true);
}

t_bool	store_ambient(t_minirt *minirt, char *line, char **data,
			char **split_rgb)
{
	double	amb_comps[4];
	char	**data_loc;

	(void)data;
	if ((minirt->bitflags & (1 << 1)) > 0)
		return (false);
	data_loc = ft_split_whitespace(line);
	if (!data_loc)
		return (false);
	if (check_correct_nr_of_inputs(data_loc, 3) == false)
	{
		free_split_array(data_loc);
		return (false);
	}
	amb_comps[3] = ft_fatoi(data_loc[1]);
	if (amb_comps[3] == FATOI_ERROR
		|| is_ambient_ratio_in_range(amb_comps) == false)
	{
		return (free_splitted_return_false((void **)data_loc));
	}
	minirt->world.ambient_factor = amb_comps[3];
	split_rgb = ft_split(data_loc[2], ',');
	if (!split_rgb)
		return (free_splitted_return_false((void **)data_loc));
	return (check_rest(minirt, split_rgb, data_loc, amb_comps));
}
