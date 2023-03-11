/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shade_hit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shade_hit.h"
#include "../inc/lighting.h"

t_color	*shade_hit(t_world *world, t_comps *comps, int remaining)
{
	t_color			*final_col;
	t_color			*surface;

	(void)remaining;
	surface = get_col_of_all_lights(world, comps, &world->shade_hit.light_calc);
	if (!surface)
		exit (1);
	final_col = surface;
	return (final_col);
}
