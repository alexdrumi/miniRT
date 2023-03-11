/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general_utils.h"
#include "../inc/general_utils3.h"
#include "../inc/macros.h"
#include <math.h>

double	deg2rad(const double angle_in_degrees)
{
	return (angle_in_degrees * (M_PI / 180));
}

t_bool	check_correct_nr_of_inputs(char **data, int nr_of_expected_inputs)
{
	int	n;

	if (!data)
		print_malloc_error_and_exit();
	n = 0;
	while (data[n] != 0)
		n++;
	if (n == nr_of_expected_inputs)
		return (true);
	else
		return (false);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

t_bool	data_to_point(char **data, double comps[3], t_minirt *minirt,
			int index)
{
	char	**split_cont;

	split_cont = ft_split(data[index], ',');
	if (!split_cont)
		return (false);
	if (check_correct_nr_of_inputs(split_cont, 3) == false)
	{
		free_split_array(split_cont);
		return (false);
	}
	if (check_correct_nr_of_inputs(split_cont, 3) == false)
	{
		free_split_array(split_cont);
		return (false);
	}
	if (check_components(split_cont, comps, minirt) == false)
	{
		free_split_array(split_cont);
		return (false);
	}
	free_split_array(split_cont);
	return (true);
}

t_bool	create_color(char **data, t_minirt *minirt,
			int index, t_color *assign_to)
{
	char	**split_mat_color;
	double	color_comps[3];

	split_mat_color = ft_split(data[index], ',');
	if (!split_mat_color)
		return (false);
	if (check_correct_nr_of_inputs(split_mat_color, 3) == false)
	{
		free_split_array(split_mat_color);
		return (false);
	}
	minirt->bitflags |= (1 << 2);
	if (check_components(split_mat_color, color_comps, minirt) == false)
	{
		free_split_array(split_mat_color);
		return (false);
	}
	set_color(assign_to, color_comps[0] / 255, color_comps[1] / 255,
		color_comps[2] / 255);
	free_split_array(split_mat_color);
	return (true);
}
