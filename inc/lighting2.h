/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING2_H
# define LIGHTING2_H
# include "structs.h"

t_color	lighting(t_comps *comps, t_lightcalcs *lights, t_pointlight *light,
			int in_shadow);
t_color	*loop_all_lights(t_world *world, t_comps *comps,
			t_color *surface, t_lightcalcs *lights);
#endif
