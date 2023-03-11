/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_ambient.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_AMBIENT_H
# define STORE_AMBIENT_H
# include "../inc/structs.h"

t_bool	store_ambient(t_minirt *minirt, char *line,
			char **data, char **split_rgb);

#endif