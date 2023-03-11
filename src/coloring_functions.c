/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coloring_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/coloring_functions.h"
#include "../inc/general_utils3.h"

t_color	*init_color(double r, double g, double b)
{
	t_color		*new_color;

	new_color = (t_color *)malloc(sizeof(t_color));
	if (!new_color)
		print_malloc_error_and_exit();
	if (r < 0 || g < 0 || b < 0)
	{
		write(1, "One or more components of color input are incorrect\n", 53);
		exit (1);
	}
	new_color->r = r;
	new_color->g = g;
	new_color->b = b;
	return (new_color);
}
