/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_camera.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_CAMERA_H
# define STORE_CAMERA_H
# include "structs.h"

t_bool	store_camera(t_minirt *minirt, char *line, char **data,
			char **split_cont);

#endif