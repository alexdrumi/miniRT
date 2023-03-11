/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lighting.h"
#include "../inc/lighting2.h"
#include "../inc/vector_operations2.h"
#include "../inc/coloring_functions.h"
#include "../inc/color_operations1.h"
#include "../inc/general_utils3.h"
#include "../inc/patterns.h"
#include "../inc/vector_operations1.h"

void	get_reflect_vector(t_vector3 *incoming,
			t_vector3 *normal, t_vector3 *res)
{
	t_vector3	scaled_normal;
	double		dot_product;

	if (!incoming || !normal || !res)
		print_malloc_error_and_exit();
	dot_product = 2 * get_dot_prod(incoming, normal);
	scalar_vec_mult_local(normal, dot_product, &scaled_normal);
	vector_min_vector(incoming, &scaled_normal, res);
}

t_color	*get_col_of_all_lights(t_world *world,
				t_comps *comps, t_lightcalcs *lights)
{
	t_color			*surface;

	surface = init_color(0, 0, 0);
	if (!surface)
		print_malloc_error_and_exit();
	if (!world->light_list)
	{
		color_mult_local(&comps->ambient_col, &comps->obj->mat.color, surface);
		return (surface);
	}
	return (loop_all_lights(world, comps, surface, lights));
}
