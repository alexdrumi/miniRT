/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations1.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS1_H
# define MATRIX_OPERATIONS1_H
# include "structs.h"

void		multiply_matrix44_point_to_point(double **m1, t_point3 *point,
				t_point3 *multiplied_point_w_matrix);
void		multiply_matrix44_vector_to_vector(double **m1, t_vector3 *vector,
				t_vector3 *multiplied_vector_w_matrix);
t_point3	*multiply_matrix44_point(double **m1, t_point3 *point);
void		get_scaling_matrix(double **m, double x, double y, double z);
void		get_translation_matrix(double **m, double x, double y, double z);

#endif
