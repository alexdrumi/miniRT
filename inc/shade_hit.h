/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shade_hit.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_HIT_H
# define SHADE_HIT_H
# include "structs.h"

t_color	*shade_hit(t_world *world, t_comps *comps, int remaining);

#endif