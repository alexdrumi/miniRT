/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_cylinder.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_LIGHTS_H
# define STORE_LIGHTS_H
# include "structs.h"

t_bool	store_lights(t_minirt *minirt, char *line,
			char **data, char **split_data_container);

#endif