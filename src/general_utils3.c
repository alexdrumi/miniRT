/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils3.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general_utils3.h"
#include "../inc/macros.h"

t_bool	free_splitted_return_false(void **splitted)
{
	if (splitted != NULL)
	{
		free_split_array((char **)splitted);
	}
	return (false);
}

void	free_split_array_void(void **splitted)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void	set_ray_origin(t_ray *ray, double x, double y, double z)
{
	ray->orig.x = x;
	ray->orig.y = y;
	ray->orig.z = z;
}

void	print_malloc_error_and_exit(void)
{
	write(1, MALLOC_ERROR, 44);
	exit(1);
}

void	free_split_array(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
