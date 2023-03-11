/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations4.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS4_H
# define MATRIX_OPERATIONS4_H
# include "../inc/structs.h"

t_bool	create_rotate_matrix(char **data, t_minirt *minirt,
			int index, t_ray_object *obj);
t_bool	create_scale_matrix(char **data, t_minirt *minirt,
			int index, double **m);
#endif