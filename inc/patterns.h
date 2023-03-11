/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patterns.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H
# include "structs.h"

t_color	*pattern_at_object(t_pattern *pattern, t_ray_object *object,
			t_point3 *world_point);

#endif
