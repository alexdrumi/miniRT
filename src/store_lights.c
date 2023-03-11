/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_lights.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/store_lights.h"
#include "../inc/init_functions2.h"
#include "../inc/general_utils.h"
#include "../inc/point_operations1.h"
#include "../inc/ft_fatoi.h"
#include "../inc/general_utils3.h"

static t_bool	create_light(t_minirt *minirt, double light_col[3],
					double light_orig[3], double brightness)
{
	t_point3		light_origin;
	t_color			color;
	t_pointlight	*light;
	t_list			*new_light;

	set_point(&light_origin, light_orig[0], light_orig[1], light_orig[2]);
	set_color(&color, light_col[0] / 255,
		light_col[1] / 255, light_col[2] / 255);
	light = init_point_light(&light_origin, &color);
	if (!light)
		return (false);
	light->diffuse = brightness;
	new_light = ft_lstnew(light);
	if (!new_light)
	{
		free(light);
		return (false);
	}
	ft_lstadd_back(&minirt->world.light_list, new_light);
	(minirt->world.light_count)++;
	minirt->bitflags |= (1 << 7);
	return (true);
}

static t_bool	check_input(t_minirt *minirt, char **data,
					double light_orig[3], char **split_data_container)
{
	char	**data1;

	(void)split_data_container;
	if (check_correct_nr_of_inputs(data, 4) == false)
		return (false);
	data1 = ft_split(data[1], ',');
	if (!data1)
		return (false);
	if (check_correct_nr_of_inputs(data1, 3) == false)
		return (free_splitted_return_false((void **)data1));
	if (check_components(data1, light_orig, minirt) == false)
		return (free_splitted_return_false((void **)data1));
	else
	{
		free_split_array(data1);
		return (true);
	}
}

static	int	amount_of_splitted_input(char **data)
{
	int	i;

	if (!data)
		return (0);
	i = 0;
	while (data[i] != NULL)
	{
		i++;
	}
	return (i);
}

static t_bool	assign_brightness(char **data, char **data3,
	double *brightness)
{
	char	**data2;

	data2 = ft_split(data[2], ',');
	if (!data2 || amount_of_splitted_input(data2) > 1)
	{
		free_split_array(data);
		return (free_splitted_return_false((void **)data3));
	}
	*brightness = ft_fatoi(*data2);
	free_split_array(data);
	free_split_array(data2);
	free_split_array(data3);
	if (*brightness == FATOI_ERROR || *brightness > 1 || *brightness < 0)
		return (false);
	return (true);
}

t_bool	store_lights(t_minirt *minirt, char *line,
			char **data, char **split_data_container)
{
	double	light_col[3];
	double	light_orig[3];
	double	light_brightness;
	char	**data3;

	if ((minirt->bitflags & (1 << 7)) > 0)
		return (false);
	data = ft_split_whitespace(line);
	if (check_input(minirt, data, light_orig, split_data_container) == false)
		return (free_splitted_return_false((void **)data));
	data3 = ft_split(data[3], ',');
	if (check_correct_nr_of_inputs(data3, 3) == false)
	{
		free_split_array(data);
		return (free_splitted_return_false((void **)data3));
	}
	minirt->bitflags |= (1 << 2);
	if (check_components(data3, light_col, minirt) == false)
	{
		free_split_array(data);
		return (free_splitted_return_false((void **)data3));
	}
	if (assign_brightness(data, data3, &light_brightness) == false)
		return (false);
	return (create_light(minirt, light_col, light_orig, light_brightness));
}
