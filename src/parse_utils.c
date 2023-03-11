/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_utils.h"
#include "../inc/general_utils3.h"
#include "../inc/general_utils.h"
#include "../inc/macros.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_bool	data_to_vector(char **data, double comps[3],
			t_minirt *minirt, int index)
{
	char	**split_orientation;

	split_orientation = ft_split(data[index], ',');
	if (!split_orientation)
		return (false);
	if (check_correct_nr_of_inputs(split_orientation, 3) == false)
		return (free_splitted_return_false((void **)split_orientation));
	minirt->bitflags |= (1 << 3);
	if (check_components(split_orientation, comps, minirt) == false)
		return (free_splitted_return_false((void **)split_orientation));
	free_split_array(split_orientation);
	return (true);
}

t_bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\n');
}

t_bool	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '#')
		return (true);
	while (line[i])
	{
		if (is_whitespace(line[i]) == false && line[i] != '#')
		{
			return (false);
		}
		i++;
	}
	return (true);
}
